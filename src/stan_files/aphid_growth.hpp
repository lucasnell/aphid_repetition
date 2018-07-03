/*
    aphidreps is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    aphidreps is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with aphidreps.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.17.0

#include <stan/model/model_header.hpp>

namespace model_aphid_growth_namespace {

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
    reader.add_event(0, 0, "start", "model_aphid_growth");
    reader.add_event(144, 144, "end", "model_aphid_growth");
    return reader;
}

#include <meta_header.hpp>
 class model_aphid_growth : public prob_grad {
private:
    int N;
    vector_d X;
public:
    model_aphid_growth(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_aphid_growth(stan::io::var_context& context__,
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

        static const char* function__ = "model_aphid_growth_namespace::model_aphid_growth";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 44;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            current_statement_begin__ = 45;
            validate_non_negative_index("X", "N", N);
            context__.validate_dims("data initialization", "X", "vector_d", context__.to_vec(N));
            validate_non_negative_index("X", "N", N);
            X = vector_d(static_cast<Eigen::VectorXd::Index>(N));
            vals_r__ = context__.vals_r("X");
            pos__ = 0;
            size_t X_i_vec_lim__ = N;
            for (size_t i_vec__ = 0; i_vec__ < X_i_vec_lim__; ++i_vec__) {
                X[i_vec__] = vals_r__[pos__++];
            }

            // validate, data variables
            current_statement_begin__ = 44;
            check_greater_or_equal(function__,"N",N,1);
            current_statement_begin__ = 45;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 48;
            ++num_params_r__;
            current_statement_begin__ = 50;
            ++num_params_r__;
            current_statement_begin__ = 51;
            ++num_params_r__;
            current_statement_begin__ = 54;
            ++num_params_r__;
            current_statement_begin__ = 55;
            ++num_params_r__;
            current_statement_begin__ = 58;
            ++num_params_r__;
            current_statement_begin__ = 59;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_aphid_growth() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("process")))
            throw std::runtime_error("variable process missing");
        vals_r__ = context__.vals_r("process");
        pos__ = 0U;
        context__.validate_dims("initialization", "process", "double", context__.to_vec());
        double process(0);
        process = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,process);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable process: ") + e.what());
        }

        if (!(context__.contains_r("mean_R0")))
            throw std::runtime_error("variable mean_R0 missing");
        vals_r__ = context__.vals_r("mean_R0");
        pos__ = 0U;
        context__.validate_dims("initialization", "mean_R0", "double", context__.to_vec());
        double mean_R0(0);
        mean_R0 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mean_R0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mean_R0: ") + e.what());
        }

        if (!(context__.contains_r("mean_alpha")))
            throw std::runtime_error("variable mean_alpha missing");
        vals_r__ = context__.vals_r("mean_alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "mean_alpha", "double", context__.to_vec());
        double mean_alpha(0);
        mean_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,mean_alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable mean_alpha: ") + e.what());
        }

        if (!(context__.contains_r("sigma_R0")))
            throw std::runtime_error("variable sigma_R0 missing");
        vals_r__ = context__.vals_r("sigma_R0");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_R0", "double", context__.to_vec());
        double sigma_R0(0);
        sigma_R0 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_R0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_R0: ") + e.what());
        }

        if (!(context__.contains_r("sigma_alpha")))
            throw std::runtime_error("variable sigma_alpha missing");
        vals_r__ = context__.vals_r("sigma_alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma_alpha", "double", context__.to_vec());
        double sigma_alpha(0);
        sigma_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma_alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma_alpha: ") + e.what());
        }

        if (!(context__.contains_r("Z_R0")))
            throw std::runtime_error("variable Z_R0 missing");
        vals_r__ = context__.vals_r("Z_R0");
        pos__ = 0U;
        context__.validate_dims("initialization", "Z_R0", "double", context__.to_vec());
        double Z_R0(0);
        Z_R0 = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,Z_R0);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_R0: ") + e.what());
        }

        if (!(context__.contains_r("Z_alpha")))
            throw std::runtime_error("variable Z_alpha missing");
        vals_r__ = context__.vals_r("Z_alpha");
        pos__ = 0U;
        context__.validate_dims("initialization", "Z_alpha", "double", context__.to_vec());
        double Z_alpha(0);
        Z_alpha = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,Z_alpha);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable Z_alpha: ") + e.what());
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

            T__ process;
            (void) process;  // dummy to suppress unused var warning
            if (jacobian__)
                process = in__.scalar_lb_constrain(0,lp__);
            else
                process = in__.scalar_lb_constrain(0);

            T__ mean_R0;
            (void) mean_R0;  // dummy to suppress unused var warning
            if (jacobian__)
                mean_R0 = in__.scalar_lb_constrain(0,lp__);
            else
                mean_R0 = in__.scalar_lb_constrain(0);

            T__ mean_alpha;
            (void) mean_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                mean_alpha = in__.scalar_lb_constrain(0,lp__);
            else
                mean_alpha = in__.scalar_lb_constrain(0);

            T__ sigma_R0;
            (void) sigma_R0;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_R0 = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_R0 = in__.scalar_lb_constrain(0);

            T__ sigma_alpha;
            (void) sigma_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma_alpha = in__.scalar_lb_constrain(0,lp__);
            else
                sigma_alpha = in__.scalar_lb_constrain(0);

            T__ Z_R0;
            (void) Z_R0;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_R0 = in__.scalar_lb_constrain(0,lp__);
            else
                Z_R0 = in__.scalar_lb_constrain(0);

            T__ Z_alpha;
            (void) Z_alpha;  // dummy to suppress unused var warning
            if (jacobian__)
                Z_alpha = in__.scalar_lb_constrain(0,lp__);
            else
                Z_alpha = in__.scalar_lb_constrain(0);


            // transformed parameters
            current_statement_begin__ = 64;
            T__ R0;
            (void) R0;  // dummy to suppress unused var warning

            stan::math::initialize(R0, DUMMY_VAR__);
            stan::math::fill(R0,DUMMY_VAR__);
            current_statement_begin__ = 65;
            T__ alpha;
            (void) alpha;  // dummy to suppress unused var warning

            stan::math::initialize(alpha, DUMMY_VAR__);
            stan::math::fill(alpha,DUMMY_VAR__);
            current_statement_begin__ = 67;
            validate_non_negative_index("X_pred", "N", N);
            Eigen::Matrix<T__,Eigen::Dynamic,1>  X_pred(static_cast<Eigen::VectorXd::Index>(N));
            (void) X_pred;  // dummy to suppress unused var warning

            stan::math::initialize(X_pred, DUMMY_VAR__);
            stan::math::fill(X_pred,DUMMY_VAR__);


            current_statement_begin__ = 69;
            stan::math::assign(R0, (mean_R0 + (sigma_R0 * Z_R0)));
            current_statement_begin__ = 70;
            stan::math::assign(alpha, (mean_alpha + (sigma_alpha * Z_alpha)));
            current_statement_begin__ = 73;
            stan::math::assign(get_base1_lhs(X_pred,1,"X_pred",1), get_base1(X,1,"X",1));
            current_statement_begin__ = 74;
            stan::model::assign(X_pred, 
                        stan::model::cons_list(stan::model::index_min_max(2, N), stan::model::nil_index_list()), 
                        add(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (N - 1)), stan::model::nil_index_list()), "X"),multiply(R0,subtract(1,multiply(alpha,exp(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (N - 1)), stan::model::nil_index_list()), "X")))))), 
                        "assigning variable X_pred");

            // validate transformed parameters
            if (stan::math::is_uninitialized(R0)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: R0";
                throw std::runtime_error(msg__.str());
            }
            if (stan::math::is_uninitialized(alpha)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: alpha";
                throw std::runtime_error(msg__.str());
            }
            for (int i0__ = 0; i0__ < N; ++i0__) {
                if (stan::math::is_uninitialized(X_pred(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: X_pred" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 64;
            check_greater_or_equal(function__,"R0",R0,0);
            current_statement_begin__ = 65;
            check_greater_or_equal(function__,"alpha",alpha,0);
            current_statement_begin__ = 67;

            // model body

            current_statement_begin__ = 81;
            lp_accum__.add(normal_log<propto__>(mean_R0, 0.28999999999999998, (0.022599999999999999 * 10)));
            current_statement_begin__ = 82;
            lp_accum__.add(normal_log<propto__>(mean_alpha, 0.0028999999999999998, (0.00036400000000000001 * 10)));
            current_statement_begin__ = 84;
            lp_accum__.add(normal_log<propto__>(sigma_R0, 0, 1));
            current_statement_begin__ = 85;
            lp_accum__.add(normal_log<propto__>(sigma_alpha, 0, (0.00036400000000000001 * 10)));
            current_statement_begin__ = 87;
            lp_accum__.add(normal_log<propto__>(Z_R0, 0, 1));
            current_statement_begin__ = 88;
            lp_accum__.add(normal_log<propto__>(Z_alpha, 0, 1));
            current_statement_begin__ = 92;
            lp_accum__.add(normal_log<propto__>(process, 1, 5));
            current_statement_begin__ = 94;
            lp_accum__.add(normal_log<propto__>(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(2, N), stan::model::nil_index_list()), "X"), stan::model::rvalue(X_pred, stan::model::cons_list(stan::model::index_min_max(2, N), stan::model::nil_index_list()), "X_pred"), process));

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
        names__.push_back("process");
        names__.push_back("mean_R0");
        names__.push_back("mean_alpha");
        names__.push_back("sigma_R0");
        names__.push_back("sigma_alpha");
        names__.push_back("Z_R0");
        names__.push_back("Z_alpha");
        names__.push_back("R0");
        names__.push_back("alpha");
        names__.push_back("X_pred");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
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
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
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
        static const char* function__ = "model_aphid_growth_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        double process = in__.scalar_lb_constrain(0);
        double mean_R0 = in__.scalar_lb_constrain(0);
        double mean_alpha = in__.scalar_lb_constrain(0);
        double sigma_R0 = in__.scalar_lb_constrain(0);
        double sigma_alpha = in__.scalar_lb_constrain(0);
        double Z_R0 = in__.scalar_lb_constrain(0);
        double Z_alpha = in__.scalar_lb_constrain(0);
        vars__.push_back(process);
        vars__.push_back(mean_R0);
        vars__.push_back(mean_alpha);
        vars__.push_back(sigma_R0);
        vars__.push_back(sigma_alpha);
        vars__.push_back(Z_R0);
        vars__.push_back(Z_alpha);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 64;
            double R0(0.0);
            (void) R0;  // dummy to suppress unused var warning

            stan::math::initialize(R0, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(R0,DUMMY_VAR__);
            current_statement_begin__ = 65;
            double alpha(0.0);
            (void) alpha;  // dummy to suppress unused var warning

            stan::math::initialize(alpha, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(alpha,DUMMY_VAR__);
            current_statement_begin__ = 67;
            validate_non_negative_index("X_pred", "N", N);
            vector_d X_pred(static_cast<Eigen::VectorXd::Index>(N));
            (void) X_pred;  // dummy to suppress unused var warning

            stan::math::initialize(X_pred, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(X_pred,DUMMY_VAR__);


            current_statement_begin__ = 69;
            stan::math::assign(R0, (mean_R0 + (sigma_R0 * Z_R0)));
            current_statement_begin__ = 70;
            stan::math::assign(alpha, (mean_alpha + (sigma_alpha * Z_alpha)));
            current_statement_begin__ = 73;
            stan::math::assign(get_base1_lhs(X_pred,1,"X_pred",1), get_base1(X,1,"X",1));
            current_statement_begin__ = 74;
            stan::model::assign(X_pred, 
                        stan::model::cons_list(stan::model::index_min_max(2, N), stan::model::nil_index_list()), 
                        add(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (N - 1)), stan::model::nil_index_list()), "X"),multiply(R0,subtract(1,multiply(alpha,exp(stan::model::rvalue(X, stan::model::cons_list(stan::model::index_min_max(1, (N - 1)), stan::model::nil_index_list()), "X")))))), 
                        "assigning variable X_pred");

            // validate transformed parameters
            current_statement_begin__ = 64;
            check_greater_or_equal(function__,"R0",R0,0);
            current_statement_begin__ = 65;
            check_greater_or_equal(function__,"alpha",alpha,0);
            current_statement_begin__ = 67;

            // write transformed parameters
        vars__.push_back(R0);
        vars__.push_back(alpha);
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
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
        return "model_aphid_growth";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        param_name_stream__.str(std::string());
        param_name_stream__ << "process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_alpha";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
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
        param_name_stream__.str(std::string());
        param_name_stream__ << "process";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "mean_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma_alpha";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "Z_alpha";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        param_name_stream__.str(std::string());
        param_name_stream__ << "R0";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "alpha";
        param_names__.push_back(param_name_stream__.str());
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "X_pred" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }

        if (!include_gqs__) return;
    }

}; // model

}

typedef model_aphid_growth_namespace::model_aphid_growth stan_model;


#endif
