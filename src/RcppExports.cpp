// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "clonewars_types.hpp"
#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// logit
NumericVector logit(NumericVector p);
RcppExport SEXP _clonewars_logit(SEXP pSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type p(pSEXP);
    rcpp_result_gen = Rcpp::wrap(logit(p));
    return rcpp_result_gen;
END_RCPP
}
// inv_logit
NumericVector inv_logit(NumericVector a);
RcppExport SEXP _clonewars_inv_logit(SEXP aSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type a(aSEXP);
    rcpp_result_gen = Rcpp::wrap(inv_logit(a));
    return rcpp_result_gen;
END_RCPP
}
// leslie_matrix
NumericMatrix leslie_matrix(IntegerVector instar_days, const double& surv_juv, NumericVector surv_adult, NumericVector repro);
RcppExport SEXP _clonewars_leslie_matrix(SEXP instar_daysSEXP, SEXP surv_juvSEXP, SEXP surv_adultSEXP, SEXP reproSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerVector >::type instar_days(instar_daysSEXP);
    Rcpp::traits::input_parameter< const double& >::type surv_juv(surv_juvSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type surv_adult(surv_adultSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type repro(reproSEXP);
    rcpp_result_gen = Rcpp::wrap(leslie_matrix(instar_days, surv_juv, surv_adult, repro));
    return rcpp_result_gen;
END_RCPP
}
// sad_leslie
NumericVector sad_leslie(NumericMatrix leslie);
RcppExport SEXP _clonewars_sad_leslie(SEXP leslieSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type leslie(leslieSEXP);
    rcpp_result_gen = Rcpp::wrap(sad_leslie(leslie));
    return rcpp_result_gen;
END_RCPP
}
// sim_clonewars_cpp
DataFrame sim_clonewars_cpp(const uint32& n_reps, const uint32& max_plant_age, const double& max_N, const std::deque<uint32>& check_for_clear, const uint32& max_t, const uint32& save_every, const double& mean_K, const double& sd_K, const double& death_prop, const double& shape1_death_mort, const double& shape2_death_mort, const bool& disp_error, const bool& demog_error, const double& sigma_x, const double& rho, const double& extinct_N, const std::vector<std::string>& aphid_name, const std::vector<arma::cube>& leslie_mat, const std::vector<arma::cube>& aphid_density_0, const std::vector<double>& alate_b0, const std::vector<double>& alate_b1, const std::vector<double>& disp_rate, const std::vector<double>& disp_mort, const std::vector<uint32>& disp_start, const std::vector<double>& pred_rate, uint32 n_threads, const bool& show_progress);
RcppExport SEXP _clonewars_sim_clonewars_cpp(SEXP n_repsSEXP, SEXP max_plant_ageSEXP, SEXP max_NSEXP, SEXP check_for_clearSEXP, SEXP max_tSEXP, SEXP save_everySEXP, SEXP mean_KSEXP, SEXP sd_KSEXP, SEXP death_propSEXP, SEXP shape1_death_mortSEXP, SEXP shape2_death_mortSEXP, SEXP disp_errorSEXP, SEXP demog_errorSEXP, SEXP sigma_xSEXP, SEXP rhoSEXP, SEXP extinct_NSEXP, SEXP aphid_nameSEXP, SEXP leslie_matSEXP, SEXP aphid_density_0SEXP, SEXP alate_b0SEXP, SEXP alate_b1SEXP, SEXP disp_rateSEXP, SEXP disp_mortSEXP, SEXP disp_startSEXP, SEXP pred_rateSEXP, SEXP n_threadsSEXP, SEXP show_progressSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const uint32& >::type n_reps(n_repsSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type max_plant_age(max_plant_ageSEXP);
    Rcpp::traits::input_parameter< const double& >::type max_N(max_NSEXP);
    Rcpp::traits::input_parameter< const std::deque<uint32>& >::type check_for_clear(check_for_clearSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type max_t(max_tSEXP);
    Rcpp::traits::input_parameter< const uint32& >::type save_every(save_everySEXP);
    Rcpp::traits::input_parameter< const double& >::type mean_K(mean_KSEXP);
    Rcpp::traits::input_parameter< const double& >::type sd_K(sd_KSEXP);
    Rcpp::traits::input_parameter< const double& >::type death_prop(death_propSEXP);
    Rcpp::traits::input_parameter< const double& >::type shape1_death_mort(shape1_death_mortSEXP);
    Rcpp::traits::input_parameter< const double& >::type shape2_death_mort(shape2_death_mortSEXP);
    Rcpp::traits::input_parameter< const bool& >::type disp_error(disp_errorSEXP);
    Rcpp::traits::input_parameter< const bool& >::type demog_error(demog_errorSEXP);
    Rcpp::traits::input_parameter< const double& >::type sigma_x(sigma_xSEXP);
    Rcpp::traits::input_parameter< const double& >::type rho(rhoSEXP);
    Rcpp::traits::input_parameter< const double& >::type extinct_N(extinct_NSEXP);
    Rcpp::traits::input_parameter< const std::vector<std::string>& >::type aphid_name(aphid_nameSEXP);
    Rcpp::traits::input_parameter< const std::vector<arma::cube>& >::type leslie_mat(leslie_matSEXP);
    Rcpp::traits::input_parameter< const std::vector<arma::cube>& >::type aphid_density_0(aphid_density_0SEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type alate_b0(alate_b0SEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type alate_b1(alate_b1SEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type disp_rate(disp_rateSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type disp_mort(disp_mortSEXP);
    Rcpp::traits::input_parameter< const std::vector<uint32>& >::type disp_start(disp_startSEXP);
    Rcpp::traits::input_parameter< const std::vector<double>& >::type pred_rate(pred_rateSEXP);
    Rcpp::traits::input_parameter< uint32 >::type n_threads(n_threadsSEXP);
    Rcpp::traits::input_parameter< const bool& >::type show_progress(show_progressSEXP);
    rcpp_result_gen = Rcpp::wrap(sim_clonewars_cpp(n_reps, max_plant_age, max_N, check_for_clear, max_t, save_every, mean_K, sd_K, death_prop, shape1_death_mort, shape2_death_mort, disp_error, demog_error, sigma_x, rho, extinct_N, aphid_name, leslie_mat, aphid_density_0, alate_b0, alate_b1, disp_rate, disp_mort, disp_start, pred_rate, n_threads, show_progress));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_clonewars_logit", (DL_FUNC) &_clonewars_logit, 1},
    {"_clonewars_inv_logit", (DL_FUNC) &_clonewars_inv_logit, 1},
    {"_clonewars_leslie_matrix", (DL_FUNC) &_clonewars_leslie_matrix, 4},
    {"_clonewars_sad_leslie", (DL_FUNC) &_clonewars_sad_leslie, 1},
    {"_clonewars_sim_clonewars_cpp", (DL_FUNC) &_clonewars_sim_clonewars_cpp, 27},
    {NULL, NULL, 0}
};

RcppExport void R_init_clonewars(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
