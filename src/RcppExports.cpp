// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "clonewars_types.hpp"
#include <RcppArmadillo.h>
#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

// sim_reps_
arma::mat sim_reps_(const uint32& n_reps, const uint32& max_t, const arma::mat& N0, const arma::rowvec& R, const arma::rowvec& A, const arma::vec& D_vec, const double& process_error, const bool& disp_error, const double& log_zeta_mean, const double& log_zeta_sd, const double& zeta_t_thresh, const double& mu_time, const std::deque<uint32>& repl_times, const double& repl_threshold, const double& extinct_N, const uint32& save_every, const bool& by_patch, const uint32& n_cores, const bool& show_progress);
RcppExport SEXP _clonewars_sim_reps_(SEXP n_repsSEXP, SEXP max_tSEXP, SEXP N0SEXP, SEXP RSEXP, SEXP ASEXP, SEXP D_vecSEXP, SEXP process_errorSEXP, SEXP disp_errorSEXP, SEXP log_zeta_meanSEXP, SEXP log_zeta_sdSEXP, SEXP zeta_t_threshSEXP, SEXP mu_timeSEXP, SEXP repl_timesSEXP, SEXP repl_thresholdSEXP, SEXP extinct_NSEXP, SEXP save_everySEXP, SEXP by_patchSEXP, SEXP n_coresSEXP, SEXP show_progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type n_reps(n_repsSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type max_t(max_tSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type N0(N0SEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type R(RSEXP);
    Rcpp::traits::input_parameter< const arma::rowvec& >::type A(ASEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type D_vec(D_vecSEXP);
    Rcpp::traits::input_parameter< const double& >::type process_error(process_errorSEXP);
    Rcpp::traits::input_parameter< const bool& >::type disp_error(disp_errorSEXP);
    Rcpp::traits::input_parameter< const double& >::type log_zeta_mean(log_zeta_meanSEXP);
    Rcpp::traits::input_parameter< const double& >::type log_zeta_sd(log_zeta_sdSEXP);
    Rcpp::traits::input_parameter< const double& >::type zeta_t_thresh(zeta_t_threshSEXP);
    Rcpp::traits::input_parameter< const double& >::type mu_time(mu_timeSEXP);
    Rcpp::traits::input_parameter< const std::deque<uint32>& >::type repl_times(repl_timesSEXP);
    Rcpp::traits::input_parameter< const double& >::type repl_threshold(repl_thresholdSEXP);
    Rcpp::traits::input_parameter< const double& >::type extinct_N(extinct_NSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type save_every(save_everySEXP);
    Rcpp::traits::input_parameter< const bool& >::type by_patch(by_patchSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type n_cores(n_coresSEXP);
    Rcpp::traits::input_parameter< const bool& >::type show_progress(show_progressSEXP);
    rcpp_result_gen = Rcpp::wrap(sim_reps_(n_reps, max_t, N0, R, A, D_vec, process_error, disp_error, log_zeta_mean, log_zeta_sd, zeta_t_thresh, mu_time, repl_times, repl_threshold, extinct_N, save_every, by_patch, n_cores, show_progress));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP _rcpp_module_boot_stan_fit4full_model_mod();
RcppExport SEXP _rcpp_module_boot_stan_fit4full_model_plant_death_mod();
RcppExport SEXP _rcpp_module_boot_stan_fit4full_model_plant_death_R_mod();
RcppExport SEXP _rcpp_module_boot_stan_fit4full_model_plant_death_RN_mod();

static const R_CallMethodDef CallEntries[] = {
    {"_clonewars_sim_reps_", (DL_FUNC) &_clonewars_sim_reps_, 19},
    {"_rcpp_module_boot_stan_fit4full_model_mod", (DL_FUNC) &_rcpp_module_boot_stan_fit4full_model_mod, 0},
    {"_rcpp_module_boot_stan_fit4full_model_plant_death_mod", (DL_FUNC) &_rcpp_module_boot_stan_fit4full_model_plant_death_mod, 0},
    {"_rcpp_module_boot_stan_fit4full_model_plant_death_R_mod", (DL_FUNC) &_rcpp_module_boot_stan_fit4full_model_plant_death_R_mod, 0},
    {"_rcpp_module_boot_stan_fit4full_model_plant_death_RN_mod", (DL_FUNC) &_rcpp_module_boot_stan_fit4full_model_plant_death_RN_mod, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_clonewars(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
