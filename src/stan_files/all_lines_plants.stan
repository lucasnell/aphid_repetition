
/*
    This version differs from `all_lines.stan` because it also models variability
    in density dependence (variable `a`) within clonal lines.
*/

data {
    int<lower=1> N_ts;                          // Number of time series (line + rep)
    int<lower=1> max_reps;                      // Max reps per time series
    int<lower=1> n_lines;                       // number of aphid lines
    int<lower=1> nobs_ts[N_ts];                 // # observations for each time series
    int<lower=1, upper=n_lines> line_ts[N_ts];  // aphid line for each time series
    matrix<lower=0>[max_reps, N_ts] X;          // log(N_t)
    // Priors for process error:
    real w_0;
    real eta;
    // Priors for growth rates:
    real mu_theta;
    real sigma_theta;
    real x_0;
    real gamma;
    // Priors for density dependence:
    real mu_phi;
    real sigma_phi;
    real y_0;
    real delta;
    real z_0;
    real zeta;
}
parameters {
    // Means (on transformed scale):
    real mu_r;
    real mu_a;
    // SDs (on transformed scale):
    real<lower=0> sd_r;
    real<lower=0> sd_a;                  // variation between lines
    vector<lower=0>[n_lines] sd_wi_a;    // variation within lines
    // Z-transforms:
    vector[n_lines] Z_r;
    vector[n_lines] Z_a;
    vector[N_ts] Z_wi_a;

    real<lower=0> process;
}
transformed parameters {

    vector<lower=0>[n_lines] r;             // estimated growth rate
    vector<lower=0, upper=1>[n_lines] a;    // estimated density dependence
    matrix[max_reps, N_ts] X_pred;          // predicted X not including process error

    r = exp(mu_r + sd_r * Z_r);
    a = inv_logit(mu_a + sd_a * Z_a);

    for (i in 1:N_ts) {
        // a for this time series:
        real a_ = inv_logit(mu_a + sd_a * Z_a[line_ts[i]] +
            Z_wi_a[i] * sd_wi_a[line_ts[i]]);
        // r for this time series:
        real r_ = r[line_ts[i]];
        // number of observations for this time series:
        int n_ = nobs_ts[i];
        // Now filling in `X_pred`:
        X_pred[1, i] = X[1, i];
        X_pred[2:n_, i] = X[1:(n_-1), i] + r_ * (1 - a_ * exp(X[1:(n_-1), i]));
        if (n_ < max_reps) for (j in (n_+1):max_reps) X_pred[j, i] = 0;
    }

}
model {

    // Process error sampling:
    process ~ cauchy(w_0, eta)T[0,];

    // Growth rate sampling:
    mu_r ~ normal(mu_theta, sigma_theta);  // mean (on transformed scale)
    sd_r ~ cauchy(x_0, gamma)T[0,];  // sd (on transformed scale)

    // Density dependence sampling:
    mu_a ~ normal(mu_phi, sigma_phi);  // among-line mean (on transformed scale)
    sd_a ~ cauchy(y_0, delta)T[0,];  // among-line sd (on transformed scale)
    for (i in 1:n_lines) {
        sd_wi_a[i] ~ cauchy(z_0, zeta)T[0,];  // within-line sd (on transformed scale)
    }

    // Z-scores:
    Z_r ~ normal(0,1);
    Z_a ~ normal(0,1);
    Z_wi_a ~ normal(0,1);

    for (i in 1:N_ts) {
        X[2:nobs_ts[i], i] ~ normal(X_pred[2:nobs_ts[i], i], process);
    }

}
