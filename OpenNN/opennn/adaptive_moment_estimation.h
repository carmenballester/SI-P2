//   OpenNN: Open Neural Networks Library
 //   www.opennn.net
 //
 //   A D A P T I V E   M O M E N T   E S T I M A T I O N
 //
 //   Artificial Intelligence Techniques SL
 //   artelnics@artelnics.com
  
 #ifndef ADAPTIVEMOMENTESTIMATION_H
 #define ADAPTIVEMOMENTESTIMATION_H
  
 // System includes
  
 #include <string>
 #include <sstream>
 #include <iostream>
 #include <fstream>
 #include <algorithm>
 #include <functional>
 #include <limits>
 #include <cmath>
 #include <ctime>
 #include <chrono>
 #include <time.h>
 #include <iostream>
 #include <ctime>
 #include <ratio>
 #include <chrono>
  
 // OpenNN includes
  
 #include "loss_index.h"
 #include "optimization_algorithm.h"
  
 namespace OpenNN
 {
  
  
  
 class AdaptiveMomentEstimation : public OptimizationAlgorithm
 {
  
 public:
  
    // DEFAULT CONSTRUCTOR
  
    explicit AdaptiveMomentEstimation();
  
    // LOSS INDEX CONSTRUCTOR
  
    explicit AdaptiveMomentEstimation(LossIndex*);
  
    // XML CONSTRUCTOR
  
    explicit AdaptiveMomentEstimation(const tinyxml2::XMLDocument&);
  
    // DESTRUCTOR
  
    virtual ~AdaptiveMomentEstimation();
  
    // Enumerations
  
  
    
  
    // Training operators
  
    const double& get_initial_learning_rate() const;
    const double& get_beta_1() const;
    const double& get_beta_2() const;
    const double& get_epsilon() const;
  
  
    // Training parameters
  
    const double& get_warning_parameters_norm() const;
    const double& get_warning_gradient_norm() const;
    const double& get_error_parameters_norm() const;
    const double& get_error_gradient_norm() const;
  
    // Stopping criteria
  
    const double& get_minimum_parameters_increment_norm() const;
    const double& get_minimum_loss_increase() const;
    const double& get_loss_goal() const;
    const double& get_gradient_norm_goal() const;
    const double& get_maximum_time() const;
    const bool& get_return_minimum_selection_error_neural_network() const;
    const bool& get_apply_early_stopping() const;
    const size_t& get_maximum_selection_failures() const;
  
    // Reserve training history
  
    const bool& get_reserve_training_error_history() const;
    const bool& get_reserve_selection_error_history() const;
  
    // Set methods
  
    void set_loss_index_pointer(LossIndex*);
  
    void set_default();
  
    void set_reserve_all_training_history(const bool&);
  
    // Training operators
  
    void set_initial_learning_rate(const double&);
    void set_beta_1(const double&);
    void set_beta_2(const double&);
    void set_epsilon(const double&);
  
    // Training parameters
  
    void set_warning_parameters_norm(const double&);
    void set_warning_gradient_norm(const double&);
    void set_error_parameters_norm(const double&);
    void set_error_gradient_norm(const double&);
    void set_maximum_epochs_number(const size_t&);
  
    // Stopping criteria
  
    void set_minimum_parameters_increment_norm(const double&);
    void set_minimum_loss_increase(const double&);
    void set_loss_goal(const double&);
    void set_gradient_norm_goal(const double&);
    void set_maximum_selection_error_increases(const size_t&);
    void set_maximum_time(const double&);
    void set_return_minimum_selection_error_neural_network(const bool&);
    void set_apply_early_stopping(const bool&);
  
    // Reserve training history
  
    void set_reserve_training_error_history(const bool&);
    void set_reserve_selection_error_history(const bool&);
  
    // Utilities
  
    void set_display_period(const size_t&);
  
    // Training methods
  
    Results perform_training();
  
  
    void perform_training_void();
  
  
    string write_optimization_algorithm_type() const;
  
    // Serialization methods
  
    Matrix<string> to_string_matrix() const;
  
    tinyxml2::XMLDocument* to_XML() const;
  
    void from_XML(const tinyxml2::XMLDocument&);
  
    void write_XML(tinyxml2::XMLPrinter&) const;
  
 private:
  
    // TRAINING OPERATORS
  
  
    double initial_learning_rate;
  
  
    double initial_decay;
  
  
    double beta_1;
  
  
    double beta_2;
  
  
    double epsilon;
  
    // TRAINING PARAMETERS
  
  
    double warning_parameters_norm;
  
  
    double warning_gradient_norm;   
  
    
    double error_parameters_norm;
  
  
    double error_gradient_norm;
  
    // Stopping criteria
  
  
    double minimum_parameters_increment_norm;
  
  
    double minimum_loss_decrease;
  
  
    double loss_goal;
  
  
    double gradient_norm_goal;
  
  
    size_t maximum_selection_failures;
  
  
    size_t maximum_iterations_number;
  
  
    size_t training_initial_batch_size;
  
  
    size_t training_maximum_batch_size;
  
  
    size_t maximum_epochs_number;
  
  
    double maximum_time;
  
  
    bool return_minimum_selection_error_neural_network;
  
  
    bool apply_early_stopping;
  
    // TRAINING HISTORY
  
  
    bool reserve_training_error_history;
  
  
    bool reserve_selection_error_history;
 };
  
 }
  
 #endif
