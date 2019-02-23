/*
 This model includes all parameters, including...
 - Among-line variability in growth rates
 - Among-line variability in density dependences
 - Among-PLANT variability in __effects of aphids on plant health__
 - Process error that is estimated by the model

 ALSO MADE ALPHA USE LOG TRANSFORM INSTEAD OF LOGIT

 */

functions {

    // For using nondimensionalized versions:
    // Note that this version has a new vector `b_` for effects of plant deterioration
    vector ricker_hat(vector X, int start, int end, real r_, real a_,
                      vector b_, real mu_, real tau_) {
        vector[end - start + 1] X_out;
        X_out[1] = X[start];
        X_out[2:(end - start + 1)] = X[start:(end - 1)] +
            r_ * (1 - a_ * b_ .* exp(tau_ * X[start:(end - 1)] + mu_));
        return X_out;
    }
}
data {

    // Indices:
    int<lower=1> n_ts;                          // number of time series (line + rep)
    int<lower=1> n_obs;                         // total number of observations
    int<lower=1> n_per[n_ts];                   // number of obs. for each time series

    // Data:
    vector<lower=0>[n_obs] X;                   // log(N_t)

    int<lower=1> n_lines;                       // number of aphid lines
    int<lower=1, upper=n_lines> L[n_ts];        // aphid line for each time series

}
transformed data {

    vector[n_obs] X_hat;
    vector[n_obs] t_hat; // z-scored time across all time series
    real mu;
    real tau;
    real theta[14] = rep_array(0.0, 14);

    for (i in 1:7) theta[(i*2)] = 1;

    mu = mean(X);
    tau = sd(X);

    X_hat = (X - mu) / tau;

    // iterate over each time series
    {
        int t = 1; // starting position in `X` and `X_hat_pred` vectors
        real mu_;
        real tau_;
        for (j in 1:n_ts) {
            for (i in 1:n_per[j]) {
                t_hat[t+i-1] = i;
            }
            t += n_per[j];
        }
        mu_ = mean(t_hat);
        tau_ = sd(t_hat);
        t_hat = (t_hat - mu_) / tau_;
    }

}
parameters {

    // Z-scores:

    vector[n_lines] Z_r;
    vector[n_lines] Z_alpha;
    vector[n_ts] Z_zeta;

    real<lower=0> sigma_hat_epsilon;        // process error
    // Means and SDs (on transformed scale):
    real rho;                               // mean growth rates: log(r)
    real<lower=0> sigma_rho;                // among-line SD in log(r)
    real phi;                               // mean density dependences: log(alpha)
    real<lower=0> sigma_phi;                // among-line SD in log(alpha)
    real psi;                               // mean deterioration of plant health
    real<lower=0> sigma_psi;                // among-plant SD in health deterioration

}
transformed parameters {

    vector[n_obs] X_hat_pred;               // predicted X_hat not including process error

    // iterate over each time series
    {
        int start = 1; // starting position in `X` and `X_hat_pred` vectors
        for (j in 1:n_ts) {
            // number of observations for this time series:
            int n_ = n_per[j];
            int end = start + n_ - 1;
            // growth rate (r) for this time series:
            real r_hat = exp(rho + sigma_rho * Z_r[L[j]]);
            // density dependence (alpha_hat) for this time series:
            real alpha_hat = exp(phi + sigma_phi * Z_alpha[L[j]]);
            // Plant health deterioration:
            real zeta_hat = exp(psi + sigma_psi * Z_zeta[j]);
            // Total effect of plant health through time:
            vector[(n_-1)] beta_hat = exp(zeta_hat * t_hat[(start+1):end]);
            // filling in predicted X_t+1 based on X_t:
            X_hat_pred[start:end] = ricker_hat(X_hat, start, end, r_hat, alpha_hat,
                                               beta_hat, mu, tau);
            // iterate `start` index:
            start += n_;
        }
    }


}
model {

    Z_r ~ normal(0, 1);                     // for growth rates by line
    Z_alpha ~ normal(0, 1);                 // for density dependence by line
    Z_zeta ~ normal(0, 1);                  // for health deterioration by plant

    sigma_hat_epsilon ~ normal(theta[1], theta[2])T[0,];
    rho  ~ normal(theta[3], theta[4]);
    sigma_rho  ~ normal(theta[5], theta[6])T[0,];
    phi  ~ normal(theta[7], 10 * theta[8]);
    sigma_phi  ~ normal(theta[9], 10 * theta[10])T[0,];
    psi  ~ normal(theta[11], theta[12]);
    sigma_psi  ~ normal(theta[13], 10 * theta[14])T[0,];

    // Process error:
    // iterate over each time series
    {
        int start = 1; // starting position in `X` and `X_hat_pred` vectors
        for (j in 1:n_ts) {
            // number of observations for this time series:
            int n_ = n_per[j];
            int end = start + n_ - 1;
            X_hat[(start+1):end]  ~ normal(X_hat_pred[(start+1):end], sigma_hat_epsilon);
            // iterate `start` index:
            start += n_;
        }
    }
}
generated quantities {

    // Residuals
    vector[n_obs] X_resid;

    /*
     Parameter estimates in original scale:
     */
    vector[n_obs] X_pred;
    vector[n_lines] R;  // growth rate by line
    vector[n_lines] A;  // alpha by line
    vector[n_ts] Z;     // zeta by plant
    real sigma_epsilon; // SD of process error

    X_resid = X_hat - X_hat_pred;

    X_pred = X_hat_pred * tau + mu;
    R = exp(rho + sigma_rho * Z_r) * tau;
    A = exp(phi + sigma_phi * Z_alpha);
    Z = psi + sigma_psi * Z_zeta;
    sigma_epsilon = sigma_hat_epsilon * tau;

}
