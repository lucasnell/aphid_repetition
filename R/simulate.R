# Create line info ----

#' Organize clonal line information
#'
#' To smooth stage structure out over time,
#' not all 4th instar aphids move to adulthood immediately.
#' If adulthood starts on day `t`, then half of aphids at age `t-2` move to
#' adulthood, and half at age `t-1` do, too.
#' I adjusted age `t-2`, too, to avoid this affecting the growth rate too much.
#'
#'
#' @param name String for clonal line name.
#' @param density_0 A 5 x 2 matrix with the rows indicating aphid instar,
#'     and column indicating apterous vs alate.
#'     Defaults to `NULL`, which results in four 4th instars.
#' @param resistant Logical or length-2 vector of survivals of
#'     singly attacked and multiply attacked aphids.
#'     If a logical, `FALSE` is equivalent to `c(0,0)` and results in no
#'     resistance.
#'     `TRUE` results in the resistance values for a resistance line
#'     from unpublished work by Anthony Ives.
#'     Defaults to `FALSE`.
#' @param surv_juv_apterous A single number for the juvenile survival rate for
#'     apterous aphids. Defaults to `NULL`, which results in estimates
#'     from a medium-reproduction line.
#' @param surv_adult_apterous A vector of adult survival probabilities for
#'     apterous aphids. Defaults to `NULL`, which results in estimates
#'     from a medium-reproduction line.
#' @param repro_apterous A vector of fecundities for for apterous aphids.
#'     Defaults to `NULL`, which results in estimates from a
#'     medium-reproduction line.
#' @param surv_juv_alates A single number for the juvenile survival rate for
#'     alates aphids. Defaults to `"low"`, which results in estimates
#'     from a low-reproduction line.
#' @param surv_adult_alates A vector of adult survival probabilities for
#'     alates aphids. Defaults to `"low"`, which results in estimates
#'     from a low-reproduction line.
#' @param repro_alates A vector of fecundities for for alates aphids.
#'     Defaults to `"low"`, which results in estimates from a low-reproduction
#'     line.
#' @param surv_paras A single number for the juvenile survival rate for
#'     paras aphids. Defaults to `"low"`, which results in estimates
#'     from a low-reproduction line.
#' @param repro_paras A vector of fecundities for for paras aphids.
#'     Defaults to `"low"`, which results in estimates from a low-reproduction
#'     line.
#' @param temp Single string specifying `"low"` (20º C) or `"high"` (27º C)
#'     temperature. Defaults to `"low"`.
#'
#' @return A list with the necessary info to pass onto sim_clonewars.
#'
#' @export
#'
clonal_line <- function(name,
                        density_0 = NULL,
                        resistant = FALSE,
                        surv_juv_apterous = NULL,
                        surv_adult_apterous = NULL,
                        repro_apterous = NULL,
                        surv_juv_alates = "low",
                        surv_adult_alates = "low",
                        repro_alates = "low",
                        surv_paras = "low",
                        temp = "low",
                        p_instar_smooth = 0.5) {


    temp <- match.arg(temp, c("low", "high"))
    temp <- paste0(temp, "T")


    # --------------*
    # Construct Leslie matrices
    # --------------*

    leslie <- list(apterous = NA,
                   alates = NA,
                   paras = NA)
    # In `leslie_mat` below, items in vector are aphid lines, slices are
    # apterous/alate/parasitized.

    # Set with default values for Leslie matrix calculations
    def_L_args <- list(instar_days = dev_times$instar_days[[temp]],
                       surv_juv = mean(do.call(c, populations$surv_juv)),
                       surv_adult = colMeans(do.call(rbind,
                                                     populations$surv_adult)),
                       repro = colMeans(do.call(rbind, populations$repro)))

    inputs <- list(surv_juv_apterous,
                   surv_juv_alates,
                   surv_paras,
                   surv_adult_apterous,
                   surv_adult_alates,
                   surv_paras,
                   repro_apterous,
                   repro_alates)
    names(inputs) <- c("surv_juv_apterous", "surv_juv_alates", "surv_juv_paras",
                       "surv_adult_apterous", "surv_adult_alates", "surv_adult_alates",
                       "repro_apterous",
                       "repro_alates")

    for (x in c("apterous", "alates", "paras")) {
        leslie_args <- def_L_args
        for (y in names(inputs)[grepl(paste0(x, "$"), names(inputs))]) {
            arg_name <- gsub(paste0("_", x), "", y)
            if (!is.null(inputs[[y]])) {
                if (is.numeric(inputs[[y]])) {
                    leslie_args[[arg_name]] <- inputs[[y]]
                } else if (inputs[[y]] %in% c("low", "high")) {
                    leslie_args[[arg_name]] <- populations[[arg_name]][[
                        inputs[[y]]]]
                } else {
                    msg <- paste0("\nERROR: input argument `", y,
                                  "` to the `clonal_line` function should be ",
                                  "NULL, a numeric vector, \"low\", or ",
                                  "\"high\"")
                    stop(msg)
                }
            }
        }
        leslie[[x]] <- do.call(leslie_matrix, leslie_args)
    }

    if (!identical(dim(leslie[[1]]), dim(leslie[[2]])) ||
        !identical(dim(leslie[[1]]), dim(leslie[[3]]))) {
        stop("\nERROR: Leslie matrices for apterous, alates, and parasitized",
             " aphids must all be of the same dimensions\n")
    }

    leslie_array <- array(do.call(c, leslie), dim = c(dim(leslie[[1]]), 3))
    ns <- nrow(leslie_array)  # number of stages; used later

    # To make 4th instars not always move to adulthood at the same time:
    if (p_instar_smooth > 0) {
        .adult <- sum(head(dev_times$instar_days[[temp]], -1)) + 1
        # I included `- 1` bc we don't to adjust the Leslie matrix for the
        # parasitized aphids
        for (j in 1:(dim(leslie_array)[3] - 1)) {
            # Of the aphids that would've moved to adulthood, make
            # `p_instar_smooth` remain as 4th instars of age `.adult-1` instead:
            .t <- .adult - 1
            surv_t <- leslie_array[.adult, .t, j]
            leslie_array[.t, .t, j] <- surv_t * p_instar_smooth
            leslie_array[.adult, .t, j] <- surv_t * (1 - p_instar_smooth)
            # Of the aphids that would've moved to age `.adult-1`, make
            # `p_instar_smooth` move to adulthood instead:
            .t <- .adult - 2
            surv_t <- leslie_array[.t+1, .t, j]
            leslie_array[.adult, .t, j] <- surv_t * p_instar_smooth
            leslie_array[.t+1, .t, j] <- surv_t * (1 - p_instar_smooth)
        }
    }



    # --------------*
    # Fill other info
    # --------------*

    attack_surv <- c(0, 0)
    if (is.logical(resistant) && resistant) attack_surv <- wasp_attack$attack_surv
    if (is.numeric(resistant) && length(resistant) == 2) attack_surv <- resistant


    if (is.null(density_0)) {
        density_0 <- matrix(0, 5, 2)
        density_0[4,1] <- 4
    }
    if (!is.matrix(density_0) || !is.numeric(density_0) ||
        !identical(dim(density_0), c(5L, 2L))) {
        stop("\nERROR: If not NULL, then the `density_0` arg to the ",
             "`clonal_line` function must be a 5x2 numeric matrix")
    }
    d0 <- density_0
    density_0 <- matrix(0, ns, 2)
    # Going from instar to days old, using the approximate middle
    # point of each instar age range:
    d0_inds <- cumsum(dev_times$instar_days[[temp]][1:4])
    d0_inds <- as.integer({c(1, d0_inds + 1) + c(d0_inds, ns)} / 2)
    for (i in 1:nrow(d0)) density_0[d0_inds[i],] <- d0[i,]


    output <- list(name = name,
                   density_0 = density_0,
                   attack_surv = attack_surv,
                   leslie = leslie_array)
    class(output) <- "aphid"

    return(output)

}


#'
#' @export
#' @noRd
#'
print.aphid <- function(x, ...) {

    cat("< Aphid clonal line >\n")
    cat("Name: ", x$name, "\n", sep = "")
    cat("Fields:\n")
    cat("  * name <string>\n")
    cat("  * density_0 <matrix>\n")
    cat("  * attack_surv <vector>\n")
    cat("  * leslie <3D array>\n")

    invisible(x)

}

#'
#' @export
#' @noRd
#'
c.aphid <- function(...) {
    z <- list(...)
    names(z) <- sapply(z, function(x) x$name)
    class(z) <- "multiAphid"
    return(z)
}

#'
#' @export
#' @noRd
#'
print.multiAphid <- function(x, ...) {
    cat("< ", length(x), "aphid clonal lines >\n")
    cat("Lines:\n")
    for (i in 1:length(x)) {
        cat("  ", i, ". ", x[[i]]$name, sep = "")
        if (sum(x[[i]][["attack_surv"]]) > 0) cat(" (resistant)")
        cat("\n")
    }
    invisible(x)
}

# Basic type checks ----
uint_check <- function(x, n) {
    if (!(is.numeric(x) && length(x) == 1 && x %% 1 == 0 && x >= 0)) {
        stop(paste("\nERROR:", n, "cannot be properly cast as an",
                   "unsigned integer.\n"))
    }
}
uint_vec_check <- function(x, n) {
    if (!(is.numeric(x) && all(x %% 1 == 0) && all(x >= 0))) {
        stop(paste("\nERROR:", n, "cannot be properly cast as an",
                   "unsigned integer vector.\n"))
    }
}
dbl_check <- function(x, n, .max = NULL, .min = NULL) {
    if (!(is.numeric(x) && length(x) == 1)) {
        stop(paste("\nERROR:", n, "cannot be properly cast as a",
                   "double.\n"))
    }
    if (!is.null(.min) && x < .min) {
        stop(paste0("\nERROR: ", n, " is below the minimum allowed value (",
                   .min, ").\n"))
    }
    if (!is.null(.max) && x > .max) {
        stop(paste0("\nERROR: ", n, " is above the maximum allowed value (",
                   .max, ").\n"))
    }
}
dbl_vec_check <- function(x, n, .max = NULL, .min = NULL) {
    if (!(is.numeric(x) && is.null(dim(x)))) {
        stop(paste("\nERROR:", n, "cannot be properly cast as a",
                   "numeric vector.\n"))
    }
    if (!is.null(.min) && any(x < .min)) {
        stop(paste0("\nERROR: ", n, " contains values below the minimum ",
                    "allowed (", .min, ").\n"))
    }
    if (!is.null(.max) && any(x > .max)) {
        stop(paste0("\nERROR: ", n, " contains values above the maximum ",
                    "allowed (", .max, ").\n"))
    }
}
dbl_mat_check <- function(x, n, .max = NULL, .min = NULL) {
    if (!(is.numeric(x) && inherits(x, "matrix"))) {
        stop(paste("\nERROR:", n, "cannot be properly cast as a",
                   "numeric matrix.\n"))
    }
    if (!is.null(.min) && any(x < .min)) {
        stop(paste0("\nERROR: ", n, " contains values below the minimum ",
                    "allowed (", .min, ").\n"))
    }
    if (!is.null(.max) && any(x > .max)) {
        stop(paste0("\nERROR: ", n, " contains values above the maximum ",
                    "allowed (", .max, ").\n"))
    }
}
cube_list_check <- function(x, n) {
    if (!(inherits(x, "list") &&
          all(sapply(x, inherits, what = "array")) &&
          all(sapply(x, function(y) length(dim(y)) == 3)))) {
        stop(paste("\nERROR:", n, "cannot be properly cast as a",
                   "list of cubes.\n"))
    }
}

# main fun docs ----

#' Simulate multiple reps and simplify output.
#'
#'
#' @param n_reps Number of reps to simulate.
#' @param n_patches Number of patches to simulate.
#' @param max_t Max time points to simulate for each rep.
#' @param N_0 Starting abundances for each aphid line on each patch.
#'     Can be a single number if you want the same value for each line on each patch,
#'     or a matrix if you want to specify everything.
#' @param R Growth rates for each line.
#' @param A Density dependence for each line.
#' @param D_vec Vector of `b0` values, where the predicted number of dispersed aphids is
#'     given by `exp(b0) * N` when `N` is the number of total aphids.
#' @param process_error SD of process error. Set to 0 for no process error.
#' @param disp_error Boolean for whether to include dispersal stochasticity.
#' @param log_zeta_mean Mean of the distribution of log(zeta) values.
#' @param log_zeta_sd SD of the distribution of log(zeta) values.
#' @param zeta_t_thresh Threshold for `exp(zeta * (t - mu_time))` that makes that
#'     patch get replaced. This is equivalent to the threshold for patch "health"
#'     that would make an experimenter replace it.
#' @param mu_time Mean of time values.
#' @param repl_times Vector of times at which to replace patches.
#' @param repl_threshold Threshold above which patches are replaced.
#' @param extinct_N Threshold below which a line is considered extinct.
#' @param save_every Abundances will be stored every `save_every` time points.
#' @param by_patch Logical for whether to summarize abundances by patch, rather
#'     than separately by line and patch.
#' @param n_cores Number of cores to use. Defaults to \code{1}.
#' @param show_progress Boolean for whether to show progress bar. Defaults to
#'     \code{FALSE}.
#' @param line_names Vector of names to assign to lines.
#'
#'
#' @importFrom purrr map_dfr
#' @importFrom dplyr as_tibble
#' @importFrom dplyr mutate
#' @importFrom tidyr gather
#' @importFrom dplyr arrange
#'
#' @export
#'
#'
# main fun code ----
sim_clonewars <- function(n_reps,
                          clonal_lines,
                          n_cages = 1,
                          n_patches = 4,
                          max_t = 100,
                          plant_check_gaps = c(3, 4),
                          max_plant_age = 1000000,
                          clear_surv = 0,
                          max_N = 0,
                          temp = "low",
                          no_error = FALSE, # <-- this being TRUE overrides all others
                          disp_error = FALSE,
                          environ_error = FALSE,
                          plant_K_error = FALSE,
                          wither_effects_error = FALSE,
                          sigma_x = environ$sigma_x,
                          sigma_y = environ$sigma_y,
                          mean_K = 1806.176,
                          sd_K = 658.4736,
                          K_y_mult = 1 / 1.57,
                          death_prop = 0.8,
                          rho = environ$rho,
                          a = wasp_attack$a,
                          k = wasp_attack$k,
                          h = wasp_attack$h,
                          wasp_density_0 = 4,
                          wasp_delay = 0,
                          sex_ratio = populations$sex_ratio,
                          s_y = populations$s_y,
                          rel_attack = NULL,
                          mum_density_0 = 0,
                          max_mum_density = 0,
                          pred_rate = 0,
                          disp_rate = 1,
                          disp_mort = 0,
                          alate_b0 = -2.988,
                          alate_b1 = 0,
                          alate_disp_prop = 0.75,
                          shape1_death_mort = 3.736386,
                          shape2_death_mort = 5.777129,
                          extinct_N = 1,
                          save_every = 1,
                          n_threads = max(parallel::detectCores()-2,1),
                          show_progress = FALSE,
                          perturb = NULL) {

    if (!inherits(clonal_lines, "multiAphid")) {
        if (inherits(clonal_lines, "aphid")) {
            clonal_lines <- c(clonal_lines)
        } else stop("\nERROR: `clonal_lines` must be a multiAphid object.\n")
    }

    temp <- match.arg(temp, c("low", "high"))

    n_lines <- length(clonal_lines)

    check_for_clear <- cumsum(rep(plant_check_gaps,
                                  ceiling(max_t / sum(plant_check_gaps))))
    check_for_clear <- check_for_clear[check_for_clear < max_t]


    if (no_error) {
        disp_error <- FALSE
        environ_error <- FALSE
        plant_K_error <- FALSE
        wither_effects_error <- FALSE
    }
    if (!environ_error) {
        demog_error <- FALSE
        sigma_x <- 0
        sigma_y <- 0
    } else demog_error <- TRUE
    if (!plant_K_error) sd_K <- 0

    if (!wither_effects_error) {
        if (shape2_death_mort > 0) {
            shape1_death_mort <- shape1_death_mort /
                (shape1_death_mort + shape2_death_mort)
            shape2_death_mort <- 0
        }
    }

    if (length(pred_rate) == 1) pred_rate <- rep(pred_rate, n_patches)
    if (length(disp_rate) == 1) disp_rate <- rep(disp_rate, n_lines)
    if (length(disp_mort) == 1) disp_mort <- rep(disp_mort, n_lines)
    if (length(alate_b0) == 1) alate_b0 <- rep(alate_b0, n_lines)
    if (length(alate_b1) == 1) alate_b1 <- rep(alate_b1, n_lines)
    if (length(wasp_density_0) == 1) wasp_density_0 <- rep(wasp_density_0,
                                                           n_cages)

    if (is.null(rel_attack)) {
        rel_attack <- wasp_attack$rel_attack
    } else stopifnot(length(rel_attack) == 5)

    if (length(mum_density_0) == 1) {
        mum_density_0 <- matrix(mum_density_0, dev_times$mum_days[2], n_patches)
    }


    living_days <- rep(dev_times$mum_days[[1]], n_lines)
    disp_start <- rep(sum(head(dev_times$instar_days[[paste0(temp, "T")]], -1)),
                      n_lines)



    # ---------------*
    # Extract from `clonal_lines`
    # ---------------*
    aphid_names <- names(clonal_lines)

    densities_0 <- lapply(clonal_lines, function(x) x$density_0)
    if (!length(unique(sapply(densities_0, nrow))) == 1) {
        stop("\nERROR: All aphid lines must have the same sized density ",
             "matrices\n")
    }
    aphid_density_0 <- array(do.call(c, densities_0),
                             dim = c(dim(densities_0[[1]]), n_lines))
    aphid_density_0 <- replicate(n_patches, aphid_density_0, simplify = FALSE)

    attack_surv <- do.call(cbind, lapply(clonal_lines, `[[`, i = "attack_surv"))

    leslie_cubes <- lapply(clonal_lines, function(x) x$leslie)

    stopifnot(length(unique(sapply(leslie_cubes, nrow))) == 1)
    stopifnot(length(unique(sapply(leslie_cubes, ncol))) == 1)
    stopifnot(length(unique(sapply(leslie_cubes, function(x) dim(x)[3]))) == 1)

    if (length(rel_attack) == 5) {
        rel_attack <- rel_attack / sum(rel_attack)
        dt <- dev_times$instar_days[[paste0(temp, "T")]]
        n_adult_days <- nrow(leslie_cubes[[1]]) - sum(head(dt, -1))
        stopifnot(n_adult_days >= 0)
        if (tail(dt, 1) != n_adult_days) dt[length(dt)] <- n_adult_days
        # Commented version isn't used bc it wasn't done this way when fitting
        # the model.
        # rel_attack__ <- mapply(function(.x, .y) rep(.x, .y) / .y,
        #                        rel_attack,  dt)
        rel_attack__ <- mapply(rep, rel_attack,  dt)
        rel_attack <- do.call(c, rel_attack__)
    } else stopifnot(length(rel_attack) == nrow(leslie_cubes[[1]]))

    if (is.null(perturb)) {
        perturb_when = integer(0)
        perturb_who = integer(0)
        perturb_how = numeric(0)
    } else {
        stopifnot(inherits(perturb, "data.frame"))
        stopifnot(identical(colnames(perturb), c("when", "who", "how")))
        perturb <- dplyr::arrange(perturb, when)
        perturb_when <- perturb$when
        perturb_how <- perturb$how
        if (is.character(perturb$who)) {
            stopifnot(all(perturb$who %in% c(aphid_names, "mummies", "wasps")))
            perturb_who <- integer(length(perturb$who))
            perturb_who[perturb$who %in% aphid_names] <- -1 +
                match(perturb$who[perturb$who %in% aphid_names], aphid_names)
            perturb_who[perturb$who == "mummies"] <- length(aphid_names)
            perturb_who[perturb$who == "wasps"] <- length(aphid_names) + 1
        } else perturb_who <- perturb$who
    }

    uint_check(n_reps, "n_reps")
    uint_check(n_cages, "n_cages")
    uint_check(max_plant_age, "max_plant_age")
    dbl_check(max_N, "max_N")
    uint_vec_check(check_for_clear, "check_for_clear")
    dbl_check(clear_surv, "clear_surv")
    uint_check(max_t, "max_t")
    uint_check(save_every, "save_every")
    dbl_check(mean_K, "mean_K")
    dbl_check(sd_K, "sd_K")
    dbl_check(K_y_mult, "K_y_mult")
    dbl_check(death_prop, "death_prop")
    dbl_check(shape1_death_mort, "shape1_death_mort")
    dbl_check(shape2_death_mort, "shape2_death_mort")
    dbl_mat_check(attack_surv, "attack_surv")
    stopifnot(inherits(disp_error, "logical") && length(disp_error) == 1)
    stopifnot(inherits(demog_error, "logical") && length(demog_error) == 1)
    dbl_check(sigma_x, "sigma_x")
    dbl_check(sigma_y, "sigma_y")
    dbl_check(rho, "rho")
    dbl_check(extinct_N, "extinct_N")
    stopifnot(inherits(aphid_names, "character"))
    cube_list_check(leslie_cubes, "leslie_cubes")
    cube_list_check(aphid_density_0, "aphid_density_0")
    stopifnot(inherits(alate_b0, "numeric"))
    stopifnot(inherits(alate_b1, "numeric"))
    dbl_check(alate_disp_prop, "alate_disp_prop")
    stopifnot(inherits(disp_rate, "numeric"))
    stopifnot(inherits(disp_mort, "numeric"))
    uint_vec_check(disp_start, "disp_start")
    uint_vec_check(living_days, "living_days")
    stopifnot(inherits(pred_rate, "numeric"))
    dbl_mat_check(mum_density_0, "mum_density_0")
    dbl_check(max_mum_density, "max_mum_density", .min = 0)
    stopifnot(inherits(rel_attack, "numeric"))
    dbl_check(a, "a")
    dbl_check(k, "k")
    dbl_check(h, "h")
    dbl_vec_check(wasp_density_0, "wasp_density_0")
    uint_check(wasp_delay, "wasp_delay")
    dbl_check(sex_ratio, "sex_ratio")
    dbl_check(s_y, "s_y")
    uint_vec_check(perturb_when, "perturb_when")
    uint_vec_check(perturb_who, "perturb_who")
    dbl_vec_check(perturb_how, "perturb_how", .min = 0)
    uint_check(n_threads, "n_threads")
    stopifnot(inherits(show_progress, "logical") && length(show_progress) == 1)


    sims <- sim_clonewars_cpp(n_reps, n_cages, max_plant_age, max_N, check_for_clear,
                              clear_surv,
                              max_t, save_every, mean_K, sd_K, K_y_mult,
                              death_prop, shape1_death_mort, shape2_death_mort,
                              attack_surv, disp_error, demog_error, sigma_x,
                              sigma_y, rho, extinct_N, aphid_names, leslie_cubes,
                              aphid_density_0, alate_b0, alate_b1,
                              alate_disp_prop,
                              disp_rate, disp_mort, disp_start, living_days, pred_rate,
                              mum_density_0, max_mum_density, rel_attack, a, k, h,
                              wasp_density_0, wasp_delay, sex_ratio, s_y,
                              perturb_when, perturb_who, perturb_how,
                              n_threads, show_progress)

    sims <- lapply(sims, as_tibble)
    sims[["aphids"]] <- sims[["aphids"]] %>%
        mutate(across(c("rep", "time", "patch"), as.integer))
    sims[["wasps"]] <- sims[["wasps"]] %>%
        mutate(across(c("rep", "time"), as.integer))

    return(sims)
}




