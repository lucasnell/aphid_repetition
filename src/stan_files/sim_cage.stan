

/*
 sim_lines <- function(R, alpha, n_reps, nobs_ts, sigma_process = 0.1) {

# Number of aphid lines:
 n_lines <- length(R)
if (length(alpha) != n_lines) {
stop("\nIn sim_lines, R and alpha must be the same length.",
     call. = FALSE)
}
if (length(n_reps) != n_lines) {
stop("\nIn sim_lines, R and n_reps must be the same length.",
     call. = FALSE)
}
# Aphid line per time series
line_ts <- c(lapply(1:length(n_reps), function(i) rep(i, n_reps[i])),
             recursive = TRUE)
# Number of time series
N_ts <- sum(n_reps)

# # Reps per aphid line
# n_reps <- as.integer(round(runif(n_lines, 3, 7)))
# # # observations per time series
# nobs_ts <- as.integer(round(runif(N_ts, 10, 15)))
# R <- round(abs(rnorm(n_lines, 0.29, 0.003)), 5)
# alpha <- round(abs(rnorm(n_lines, 0.002, 0.0003)), 5)


sigma_process <- sigma_process[1]


X <- matrix(NA, max(nobs_ts), N_ts)
X[1,] <- log(runif(ncol(X), 15, 25))
for (i in 1:N_ts) {
for (t in 1:(nobs_ts[i]-1)) {
X[(t+1),i] <- X[t,i] + R[line_ts[i]] *
(1 - alpha[line_ts[i]] * exp(X[t,i])) + rnorm(1, 0, sigma_process)
}
}

return(X)
}

 */


data {
    int<lower=1> n_plants;                   // Number of plants per cage
    int<lower=1> n_lines;                       // number of aphid lines per cage
    matrix<lower=0>[n_plants, n_lines] X_0;     // log(N) at time t=0
    int<lower=1> max_t;                         // Time steps per cage
    vector<lower=0>[n_lines] R;                 // Max growth rates per aphid line
    vector<lower=0,upper=1>[n_lines] A;         // Density dependence per aphid line
    vector[n_lines] D_slope;                    // Dispersal slope per aphid line
    vector[n_lines] D_inter;                    // Dispersal intercept per aphid line
    real<lower=0> process_error;                // SD of process error
}
generated quantities {

    matrix[max_t+1, n_lines] X_out[n_plants];     // 3D array for output

    // Fill with initial values:
    for (i in 1:n_plants) {
        X_out[i] = rep_matrix(negative_infinity(), max_t+1, n_lines);
        for (j in 1:n_lines) {
            X_out[i][1,j] = X_0[i,j];
        }
    }

    {
        // Matrix to keep track of extinctions
        matrix[n_plants, n_lines] extinct = rep_matrix(0, n_plants, n_lines);
        // For calculation of dispersal
        real immigration;
        real emigration;

        for (t in 1:max_t) {

            /*
             Go through once to get some parameters first:
            */
            // Dispersal lambdas (for Poisson distr.) for all lines and plants
            matrix[n_lines, n_plants] D_lambdas;
            // Summed density dependences * N_t among all lines for each plant
            vector[n_plants] Z = rep_vector(0, n_plants);
            for (i in 1:n_plants) {
                for (j in 1:n_lines) {
                    D_lambdas[j,i] = exp(D_inter[j] + D_slope[j] * X_out[i][t,j]);
                    Z[i] += (A[j] * exp(X_out[i][t,j]));
                }
            }

            /*
             Now go back through to simulate at time t+1
            */
            for (i in 1:n_plants) {

                for (j in 1:n_lines) {

                    // Calculate the net influx of this aphid line from other plants.
                    immigration = poisson_rng((sum(D_lambdas[j,]) - D_lambdas[j,i]) /
                        (n_plants - 1));
                    emigration = poisson_rng(D_lambdas[j,i]);

                    // If it's extinct and no one's coming in, skip the rest
                    if (extinct[i,j] == 1 && immigration == 0) continue;

                    // Calculate new X based on growth and density dependence:
                    X_out[i][t+1,j] = X_out[i][t,j] + R[j] * (1 - Z[i]);
                    // Add process error:
                    X_out[i][t+1,j] += (normal_rng(0, 1) * process_error);

                    // Now temporary convert X to units of N, to add dispersal:
                    X_out[i][t+1,j] = exp(X_out[i][t+1,j]) + immigration - emigration;

                    // Convert back to units of X, but check for extinction first
                    if (X_out[i][t+1,j] < 1) {
                        X_out[i][t+1,j] = negative_infinity();
                        extinct[i,j] = 1;
                    } else X_out[i][t+1,j] = log(X_out[i][t+1,j]);

                }

            }

        }

    }


}