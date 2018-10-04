/*
    clonewars is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    clonewars is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with clonewars.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.17.0

#include <stan/model/model_header.hpp>

namespace model_no_among_r_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_no_among_r");
    reader.add_event(107, 107, "end", "model_no_among_r");
    return reader;
}

template <typename T0__, typename T3__, typename T4__>
Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T3__, T4__>::type, Eigen::Dynamic,1>
ricker(const Eigen::Matrix<T0__, Eigen::Dynamic,1>& X,
           const int& start,
           const int& end,
           const T3__& r_,
           const T4__& a_, std::ostream* pstream__) {
    typedef typename boost::math::tools::promote_args<T0__, T3__, T4__>::type fun_scalar_t__;
    typedef fun_scalar_t__ fun_return_scalar_t__;
    const static bool propto__ = true;
    (void) propto__;
        fun_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

    int current_statement_begin__ = -1;
    try {
        {
        current_statement_begin__ = 12;
        validate_non_negative_index("X_out", "((end - start) + 1)", ((end - start) + 1));
        Eigen::Matrix<fun_scalar_t__,Eigen::Dynamic,1>  X_out(static_cast<Eigen::VectorXd::Index>(((end - start) + 1)));
        (void) X_out;  // dummy to suppress unused var warning

        stan::math::initialize(X_out, std::numeric_limits<double>::quiet_NaN());
        stan::math::fill(X_out,DUMMY_VAR__);


        current_statement_begin__ = 13;
        stan::math::assign(get_base1_lhs(X_out,1,"X_out",1), get_base1(X,start,"X",1));
        current_statement_begin__ = 14;
        stan::model::assign(X_out, 
                    stan::model::cons_list(stan::model::index_min_max(2, ((end - start) + 1)), stan::model::nil_index_list()), 
                    add(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(start, (end - 1)), stan::model::nil_index_list()), "X"),multiply(r_,subtract(1,multiply(a_,exp(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(start, (end - 1)), stan::model::nil_index_list()), "X")))))), 
                    "assigning variable X_out");
        current_statement_begin__ = 16;
        return stan::math::promote_scalar<fun_return_scalar_t__>(X_out);
        }
    } catch (const std::exception& e) {
        stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
        // Next line prevents compiler griping about no return
        throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
    }
}


struct ricker_functor__ {
    template <typename T0__, typename T3__, typename T4__>
        Eigen::Matrix<typename boost::math::tools::promote_args<T0__, T3__, T4__>::type, Eigen::Dynamic,1>
    operator()(const Eigen::Matrix<T0__, Eigen::Dynamic,1>& X,
           const int& start,
           const int& end,
           const T3__& r_,
           const T4__& a_, std::ostream* pstream__) const {
        return ricker(X, start, end, r_, a_, pstream__);
    }
};

#include <meta_header.hpp>
 class model_no_among_r : public prob_grad {
private:
    int n_ts;
    int n_obs;
    vector<int> n_per;
    vector_d X;
    int n_lines;
    vector<int> L;
    vector<double> theta;
public:
    model_no_among_r(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_no_among_r(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_no_among_r_namespace::model_no_among_r";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 23;
            context__.validate_dims("data initialization", "n_ts", "int", context__.to_vec());
            n_ts = int(0);
            vals_i__ = context__.vals_i("n_ts");
            pos__ = 0;
            n_ts = vals_i__[pos__++];
            current_statement_begin__ = 24;
            context__.validate_dims("data initialization", "n_obs", "int", context__.to_vec());
            n_obs = int(0);
            vals_i__ = context__.vals_i("n_obs");
            pos__ = 0;
            n_obs = vals_i__[pos__++];
            current_statement_begin__ = 25;
            validate_non_negative_index("n_per", "n_ts", n_ts);
            context__.validate_dims("data initialization", "n_per", "int", context__.to_vec(n_ts));
            validate_non_negative_index("n_per", "n_ts", n_ts);
            n_per = std::vector<int>(n_ts,int(0));
            vals_i__ = context__.vals_i("n_per");
            pos__ = 0;
            size_t n_per_limit_0__ = n_ts;
            for (size_t i_0__ = 0; i_0__ < n_per_limit_0__; ++i_0__) {
                n_per[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 28;
            validate_non_negative_index("X", "n_obs", n_obs);
            context__.validate_dims("data initialization", "X", "vector_d", context__.to_vec(n_obs));
            validate_non_negative_index("X", "n_obs", n_obs);
            X = vector_d(static_cast<Eigen::VectorXd::Index>(n_obs));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_i_vec_lim__ = n_obs;
            for (size_t i_vec__ = 0; i_vec__ < X_i_vec_lim__; ++i_vec__) {
                X[i_vec__] = vals_r__[pos__++];
            }
            current_statement_begin__ = 30;
            context__.validate_dims("data initialization", "n_lines", "int", context__.to_vec());
            n_lines = int(0);
            vals_i__ = context__.vals_i("n_lines");
            pos__ = 0;
            n_lines = vals_i__[pos__++];
            current_statement_begin__ = 31;
            validate_non_negative_index("L", "n_ts", n_ts);
            context__.validate_dims("data initialization", "L", "int", context__.to_vec(n_ts));
            validate_non_negative_index("L", "n_ts", n_ts);
            L = std::vector<int>(n_ts,int(0));
            vals_i__ = context__.vals_i("L");
            pos__ = 0;
            size_t L_limit_0__ = n_ts;
            for (size_t i_0__ = 0; i_0__ < L_limit_0__; ++i_0__) {
                L[i_0__] = vals_i__[pos__++];
            }
            current_statement_begin__ = 34;
            validate_non_negative_index("theta", "12", 12);
            context__.validate_dims("data initialization", "theta", "double", context__.to_vec(12));
            validate_non_negative_index("theta", "12", 12);
            theta = std::vector<double>(12,double(0));
            vals_r__ = context__.vals_r("theta");
            pos__ = 0;
            size_t theta_limit_0__ = 12;
            for (size_t i_0__ = 0; i_0__ < theta_limit_0__; ++i_0__) {
                theta[i_0__] = vals_r__[pos__++];
            }

            // validate, data variables
            current_statement_begin__ = 23;
            check_greater_or_equal(function__,"n_ts",n_ts,1);
            current_statement_begin__ = 24;
            check_greater_or_equal(function__,"n_obs",n_obs,1);
            current_statement_begin__ = 25;
            for (int k0__ = 0; k0__ < n_ts; ++k0__) {
                check_greater_or_equal(function__,"n_per[k0__]",n_per[k0__],1);
            }
            current_statement_begin__ = 28;
            check_greater_or_equal(function__,"X",X,0);
            current_statement_begin__ = 30;
            check_greater_or_equal(function__,"n_lines",n_lines,1);
            current_statement_begin__ = 31;
            for (int k0__ = 0; k0__ < n_ts; ++k0__) {
                check_greater_or_equal(function__,"L[k0__]",L[k0__],1);
                check_less_or_equal(function__,"L[k0__]",L[k0__],n_lines);
            }
            current_statement_begin__ = 34;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 55;
            validate_non_negative_index("Z_a_a", "n_lines", n_lines);
            num_params_r__ += n_lines;
            current_statement_begin__ = 56;
            validate_non_negative_index("Z_a_w", "n_ts", n_ts);
            num_params_r__ += n_ts;
            current_statement_begin__ = 58;
            ++num_params_r__;
            current_statement_begin__ = 60;
            ++num_params_r__;
            current_statement_begin__ = 62;
            ++num_params_r__;
            current_statement_begin__ = 63;
            ++num_params_r__;
            current_statement_begin__ = 64;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_no_among_r() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("Z_a_a")))
            throw std::runtime_error("variable Z_a_a missing");
        vals_r__ = context__.vals_r("Z_a_a");
        pos__ = 0U;
        validate_non_negative_index("Z_a_a", "n_lines", n_lines);
        context__.validate_dims("initialization", "Z_a_a", "vector_d", context__.to_vec(n_lines));
        vector_d Z_a_a(static_cast<Eigen::VectorXd::Index>(n_lines));
        for (int j1__ = 0U; j1__ < n_lines; ++j1__)
            Z_a_a(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_unconstrain(Z_a_a);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_a_a: ") + e.what());
        }

        if (!(context__.contains_r("Z_a_w")))
            throw std::runtime_error("variable Z_a_w missing");
        vals_r__ = context__.vals_r("Z_a_w");
        pos__ = 0U;
        validate_non_negative_index("Z_a_w", "n_ts", n_ts);
        context__.validate_dims("initialization", "Z_a_w", "vector_d", context__.to_vec(n_ts));
        vector_d Z_a_w(static_cast<Eigen::VectorXd::Index>(n_ts));
        for (int j1__ = 0U; j1__ < n_ts; ++j1__)
            Z_a_w(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_unconstrain(Z_a_w);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_a_w: ") + e.what());
        }

        if (!(context__.contains_r("sigma_epsilon")))
            throw std::runtime_error("variable sigma_epsilon missing");
        vals_r__ = context__.vals_r("sigma_epsilon");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_epsilon", "double", context__.to_vec());
        double sigma_epsilon(0);
        sigma_epsilon = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_epsilon);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_epsilon: ") + e.what());
        }

        if (!(context__.contains_r("rho")))
            throw std::runtime_error("variable rho missing");
        vals_r__ = context__.vals_r("rho");
        pos__ = 0U;
        context__.validate_dims("initialization", "rho", "double", context__.to_vec());
        double rho(0);
        rho = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(rho);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable rho: ") + e.what());
        }

        if (!(context__.contains_r("phi")))
            throw std::runtime_error("variable phi missing");
        vals_r__ = context__.vals_r("phi");
        pos__ = 0U;
        context__.validate_dims("initialization", "phi", "double", context__.to_vec());
        double phi(0);
        phi = vals_r__[pos__++];
        try {
            writer__.scalar_unconstrain(phi);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable phi: ") + e.what());
        }

        if (!(context__.contains_r("sigma_phi_a")))
            throw std::runtime_error("variable sigma_phi_a missing");
        vals_r__ = context__.vals_r("sigma_phi_a");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_phi_a", "double", context__.to_vec());
        double sigma_phi_a(0);
        sigma_phi_a = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_phi_a);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_phi_a: ") + e.what());
        }

        if (!(context__.contains_r("sigma_phi_w")))
            throw std::runtime_error("variable sigma_phi_w missing");
        vals_r__ = context__.vals_r("sigma_phi_w");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_phi_w", "double", context__.to_vec());
        double sigma_phi_w(0);
        sigma_phi_w = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_phi_w);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_phi_w: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<T__> in__(params_r__,params_i__);

            Eigen::Matrix<T__,Eigen::Dynamic,1>  Z_a_a;
            (void) Z_a_a;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_a_a = in__.vector_constrain(n_lines,lp__);
            else
                Z_a_a = in__.vector_constrain(n_lines);

            Eigen::Matrix<T__,Eigen::Dynamic,1>  Z_a_w;
            (void) Z_a_w;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_a_w = in__.vector_constrain(n_ts,lp__);
            else
                Z_a_w = in__.vector_constrain(n_ts);

            T__ sigma_epsilon;
            (void) sigma_epsilon;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_epsilon = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_epsilon = in__.scalar_lb_constrain(0);

            T__ rho;
            (void) rho;  // dummy to suppress unused var warning
            if (jacobian__)
                rho = in__.scalar_constrain(lp__);
            else
                rho = in__.scalar_constrain();

            T__ phi;
            (void) phi;  // dummy to suppress unused var warning
            if (jacobian__)
                phi = in__.scalar_constrain(lp__);
            else
                phi = in__.scalar_constrain();

            T__ sigma_phi_a;
            (void) sigma_phi_a;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_phi_a = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_phi_a = in__.scalar_lb_constrain(0);

            T__ sigma_phi_w;
            (void) sigma_phi_w;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_phi_w = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_phi_w = in__.scalar_lb_constrain(0);


            // transformed parameters
            current_statement_begin__ = 69;
            validate_non_negative_index("X_pred", "n_obs", n_obs);
            Eigen::Matrix<T__,Eigen::Dynamic,1>  X_pred(static_cast<Eigen::VectorXd::Index>(n_obs));
            (void) X_pred;  // dummy to suppress unused var warning

            stan::math::initialize(X_pred, DUMMY_VAR__);
            stan::math::fill(X_pred,DUMMY_VAR__);


            {
            current_statement_begin__ = 73;
            int start(0);
            (void) start;  // dummy to suppress unused var warning

            stan::math::fill(start, std::numeric_limits<int>::min());
            stan::math::assign(start,1);


            current_statement_begin__ = 74;
            for (int j = 1; j <= n_ts; ++j) {
                {
                current_statement_begin__ = 76;
                int n_(0);
                (void) n_;  // dummy to suppress unused var warning

                stan::math::fill(n_, std::numeric_limits<int>::min());
                stan::math::assign(n_,get_base1(n_per,j,"n_per",1));
                current_statement_begin__ = 77;
                int end(0);
                (void) end;  // dummy to suppress unused var warning

                stan::math::fill(end, std::numeric_limits<int>::min());
                stan::math::assign(end,((start + n_) - 1));
                current_statement_begin__ = 79;
                T__ r_;
                (void) r_;  // dummy to suppress unused var warning

                stan::math::initialize(r_, DUMMY_VAR__);
                stan::math::fill(r_,DUMMY_VAR__);
                stan::math::assign(r_,exp(rho));
                current_statement_begin__ = 81;
                T__ a_;
                (void) a_;  // dummy to suppress unused var warning

                stan::math::initialize(a_, DUMMY_VAR__);
                stan::math::fill(a_,DUMMY_VAR__);
                stan::math::assign(a_,inv_logit(((phi + (sigma_phi_a * get_base1(Z_a_a,get_base1(L,j,"L",1),"Z_a_a",1))) + (sigma_phi_w * get_base1(Z_a_w,j,"Z_a_w",1)))));


                current_statement_begin__ = 84;
                stan::model::assign(X_pred, 
                            stan::model::cons_list(stan::model::index_min_max(start, end), stan::model::nil_index_list()), 
                            ricker(X,start,end,r_,a_, pstream__), 
                            "assigning variable X_pred");
                current_statement_begin__ = 86;
                stan::math::assign(start, (start + n_));
                }
            }
            }

            // validate transformed parameters
            for (int i0__ = 0; i0__ < n_obs; ++i0__) {
                if (stan::math::is_uninitialized(X_pred(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: X_pred" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 69;

            // model body

            current_statement_begin__ = 95;
            lp_accum__.add(normal_log<propto__>(Z_a_a, 0, 1));
            current_statement_begin__ = 96;
            lp_accum__.add(normal_log<propto__>(Z_a_w, 0, 1));
            current_statement_begin__ = 98;
            lp_accum__.add(normal_log<propto__>(sigma_epsilon, get_base1(theta,1,"theta",1), get_base1(theta,2,"theta",1)));
            if (sigma_epsilon < 0) lp_accum__.add(-std::numeric_limits<double>::infinity());
            else lp_accum__.add(-normal_ccdf_log(0, get_base1(theta,1,"theta",1), get_base1(theta,2,"theta",1)));
            current_statement_begin__ = 99;
            lp_accum__.add(normal_log<propto__>(rho, get_base1(theta,3,"theta",1), get_base1(theta,4,"theta",1)));
            current_statement_begin__ = 101;
            lp_accum__.add(normal_log<propto__>(phi, get_base1(theta,7,"theta",1), get_base1(theta,8,"theta",1)));
            current_statement_begin__ = 102;
            lp_accum__.add(normal_log<propto__>(sigma_phi_a, get_base1(theta,9,"theta",1), get_base1(theta,10,"theta",1)));
            if (sigma_phi_a < 0) lp_accum__.add(-std::numeric_limits<double>::infinity());
            else lp_accum__.add(-normal_ccdf_log(0, get_base1(theta,9,"theta",1), get_base1(theta,10,"theta",1)));
            current_statement_begin__ = 103;
            lp_accum__.add(normal_log<propto__>(sigma_phi_w, get_base1(theta,11,"theta",1), get_base1(theta,12,"theta",1)));
            if (sigma_phi_w < 0) lp_accum__.add(-std::numeric_limits<double>::infinity());
            else lp_accum__.add(-normal_ccdf_log(0, get_base1(theta,11,"theta",1), get_base1(theta,12,"theta",1)));
            current_statement_begin__ = 106;
            lp_accum__.add(normal_log<propto__>(X, X_pred, sigma_epsilon));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("Z_a_a");
        names__.push_back("Z_a_w");
        names__.push_back("sigma_epsilon");
        names__.push_back("rho");
        names__.push_back("phi");
        names__.push_back("sigma_phi_a");
        names__.push_back("sigma_phi_w");
        names__.push_back("X_pred");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(n_lines);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_ts);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(n_obs);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "model_no_among_r_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d Z_a_a = in__.vector_constrain(n_lines);
        vector_d Z_a_w = in__.vector_constrain(n_ts);
        double sigma_epsilon = in__.scalar_lb_constrain(0);
        double rho = in__.scalar_constrain();
        double phi = in__.scalar_constrain();
        double sigma_phi_a = in__.scalar_lb_constrain(0);
        double sigma_phi_w = in__.scalar_lb_constrain(0);
            for (int k_0__ = 0; k_0__ < n_lines; ++k_0__) {
            vars__.push_back(Z_a_a[k_0__]);
            }
            for (int k_0__ = 0; k_0__ < n_ts; ++k_0__) {
            vars__.push_back(Z_a_w[k_0__]);
            }
        vars__.push_back(sigma_epsilon);
        vars__.push_back(rho);
        vars__.push_back(phi);
        vars__.push_back(sigma_phi_a);
        vars__.push_back(sigma_phi_w);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 69;
            validate_non_negative_index("X_pred", "n_obs", n_obs);
            vector_d X_pred(static_cast<Eigen::VectorXd::Index>(n_obs));
            (void) X_pred;  // dummy to suppress unused var warning

            stan::math::initialize(X_pred, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(X_pred,DUMMY_VAR__);


            {
            current_statement_begin__ = 73;
            int start(0);
            (void) start;  // dummy to suppress unused var warning

            stan::math::fill(start, std::numeric_limits<int>::min());
            stan::math::assign(start,1);


            current_statement_begin__ = 74;
            for (int j = 1; j <= n_ts; ++j) {
                {
                current_statement_begin__ = 76;
                int n_(0);
                (void) n_;  // dummy to suppress unused var warning

                stan::math::fill(n_, std::numeric_limits<int>::min());
                stan::math::assign(n_,get_base1(n_per,j,"n_per",1));
                current_statement_begin__ = 77;
                int end(0);
                (void) end;  // dummy to suppress unused var warning

                stan::math::fill(end, std::numeric_limits<int>::min());
                stan::math::assign(end,((start + n_) - 1));
                current_statement_begin__ = 79;
                double r_(0.0);
                (void) r_;  // dummy to suppress unused var warning

                stan::math::initialize(r_, std::numeric_limits<double>::quiet_NaN());
                stan::math::fill(r_,DUMMY_VAR__);
                stan::math::assign(r_,exp(rho));
                current_statement_begin__ = 81;
                double a_(0.0);
                (void) a_;  // dummy to suppress unused var warning

                stan::math::initialize(a_, std::numeric_limits<double>::quiet_NaN());
                stan::math::fill(a_,DUMMY_VAR__);
                stan::math::assign(a_,inv_logit(((phi + (sigma_phi_a * get_base1(Z_a_a,get_base1(L,j,"L",1),"Z_a_a",1))) + (sigma_phi_w * get_base1(Z_a_w,j,"Z_a_w",1)))));


                current_statement_begin__ = 84;
                stan::model::assign(X_pred, 
                            stan::model::cons_list(stan::model::index_min_max(start, end), stan::model::nil_index_list()), 
                            ricker(X,start,end,r_,a_, pstream__), 
                            "assigning variable X_pred");
                current_statement_begin__ = 86;
                stan::math::assign(start, (start + n_));
                }
            }
            }

            // validate transformed parameters
            current_statement_begin__ = 69;

            // write transformed parameters
            for (int k_0__ = 0; k_0__ < n_obs; ++k_0__) {
            vars__.push_back(X_pred[k_0__]);
            }

            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_no_among_r";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= n_lines; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "Z_a_a" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_ts; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "Z_a_w" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_epsilon";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "rho";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_phi_a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_phi_w";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_0__ = 1; k_0__ <= n_obs; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "X_pred" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= n_lines; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "Z_a_a" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        for (int k_0__ = 1; k_0__ <= n_ts; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "Z_a_w" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_epsilon";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "rho";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "phi";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_phi_a";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_phi_w";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_0__ = 1; k_0__ <= n_obs; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "X_pred" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }

}; // model

}

typedef model_no_among_r_namespace::model_no_among_r stan_model;


#endif
