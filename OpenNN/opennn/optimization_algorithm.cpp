//   OpenNN: Open Neural Networks Library
 //   www.opennn.net
 //
 //   O P T I M I Z A T I O N   A L G O R I T H M   C L A S S               
 //
 //   Artificial Intelligence Techniques SL
 //   artelnics@artelnics.com
  
 #include "optimization_algorithm.h"
  
 namespace OpenNN
 {
  
  
 OptimizationAlgorithm::OptimizationAlgorithm()
  : loss_index_pointer(nullptr)
 { 
    set_default();
 }
  
  
  
 OptimizationAlgorithm::OptimizationAlgorithm(LossIndex* new_loss_index_pointer)
  : loss_index_pointer(new_loss_index_pointer)
 {
    set_default();
 }
  
  
  
 OptimizationAlgorithm::OptimizationAlgorithm(const tinyxml2::XMLDocument& document)
  : loss_index_pointer(nullptr)
 { 
    from_XML(document);
 }
  
  
  
 OptimizationAlgorithm::~OptimizationAlgorithm()
 { 
 }
  
  
  
 LossIndex* OptimizationAlgorithm::get_loss_index_pointer() const
 {
     #ifdef __OPENNN_DEBUG__
  
     if(!loss_index_pointer)
     {
         ostringstream buffer;
  
         buffer << "OpenNN Exception: OptimizationAlgorithm class.\n"
                << "LossIndex* get_loss_index_pointer() const method.\n"
                << "Loss index pointer is nullptr.\n";
  
         throw logic_error(buffer.str());
     }
  
     #endif
  
    return(loss_index_pointer);
 }
  
  
  
 bool OptimizationAlgorithm::has_loss_index() const
 {
     if(loss_index_pointer)
     {
         return true;
     }
     else
     {
         return false;
     }
 }
  
  
  
 const bool& OptimizationAlgorithm::get_display() const
 {
    return display;
 }
  
  
  
 const size_t& OptimizationAlgorithm::get_display_period() const
 {
    return(display_period);
 }
  
  
  
 const size_t& OptimizationAlgorithm::get_save_period() const
 {
    return(save_period);
 }
  
  
  
 const string& OptimizationAlgorithm::get_neural_network_file_name() const
 {
    return(neural_network_file_name);
 }
  
  
  
 void OptimizationAlgorithm::set()
 {
    loss_index_pointer = nullptr;
  
    set_default();
 }
  
  
  
 void OptimizationAlgorithm::set(LossIndex* new_loss_index_pointer)
 {
    loss_index_pointer = new_loss_index_pointer;
  
    set_default();
 }
  
  
  
 void OptimizationAlgorithm::set_loss_index_pointer(LossIndex* new_loss_index_pointer)
 {
    loss_index_pointer = new_loss_index_pointer;
 }
  
  
  
 void OptimizationAlgorithm::set_display(const bool& new_display)
 {
    display = new_display;
 }
  
  
  
 void OptimizationAlgorithm::set_display_period(const size_t& new_display_period)
 {
    
  
    #ifdef __OPENNN_DEBUG__
  
    if(new_display_period <= 0)
    {
       ostringstream buffer;
  
       buffer << "OpenNN Exception: ConjugateGradient class.\n"
              << "void set_display_period(const size_t&) method.\n"
              << "Display period must be greater than 0.\n";
  
       throw logic_error(buffer.str());
    }
  
    #endif
  
    display_period = new_display_period;
 }
  
  
  
 void OptimizationAlgorithm::set_save_period(const size_t& new_save_period)
 {
    
  
    #ifdef __OPENNN_DEBUG__
  
    if(new_save_period <= 0)
    {
       ostringstream buffer;
  
       buffer << "OpenNN Exception: ConjugateGradient class.\n"
              << "void set_save_period(const size_t&) method.\n"
              << "Save period must be greater than 0.\n";
  
       throw logic_error(buffer.str());
    }
  
    #endif
  
    save_period = new_save_period;
 }
  
  
  
 void OptimizationAlgorithm::set_neural_network_file_name(const string& new_neural_network_file_name)
 {
    neural_network_file_name = new_neural_network_file_name;
 }
  
  
  
 void OptimizationAlgorithm::set_default()
 {
    display = true;
  
    display_period = 5;
  
    save_period = UINT_MAX;
  
    neural_network_file_name = "neural_network.xml";
 }
  
  
  
 void OptimizationAlgorithm::check() const
 {
 #ifdef __OPENNN_DEBUG__
  
    ostringstream buffer;
  
    if(!loss_index_pointer)
    {
       buffer << "OpenNN Exception: OptimizationAlgorithm class.\n"
              << "void check() const method.\n"
              << "Pointer to loss index is nullptr.\n";
  
       throw logic_error(buffer.str());    
    }
  
    const NeuralNetwork* neural_network_pointer = loss_index_pointer->get_neural_network_pointer();
  
    if(neural_network_pointer == nullptr)
    {
       buffer << "OpenNN Exception: OptimizationAlgorithm class.\n"
              << "void check() const method.\n"
              << "Pointer to neural network is nullptr.\n";
  
       throw logic_error(buffer.str());
    }
  
 #endif
 }
  
  
  
 tinyxml2::XMLDocument* OptimizationAlgorithm::to_XML() const
 {
     ostringstream buffer;
  
     tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument;
  
     // Nueral network outputs integrals
  
     tinyxml2::XMLElement* optimization_algorithm_element = document->NewElement("OptimizationAlgorithm");
  
     document->InsertFirstChild(optimization_algorithm_element);
  
     // Display
     {
        tinyxml2::XMLElement* element = document->NewElement("Display");
        optimization_algorithm_element->LinkEndChild(element);
  
        buffer.str("");
        buffer << display;
  
        tinyxml2::XMLText* text = document->NewText(buffer.str().c_str());
        element->LinkEndChild(text);
     }
  
     return document;
 }
  
  
  
 void OptimizationAlgorithm::write_XML(tinyxml2::XMLPrinter& file_stream) const
 {
     ostringstream buffer;
  
     file_stream.OpenElement("OptimizationAlgorithm");
  
     // Display
  
     file_stream.OpenElement("Display");
  
     buffer.str("");
     buffer << display;
  
     file_stream.PushText(buffer.str().c_str());
  
     file_stream.CloseElement();
  
  
     file_stream.CloseElement();
 }
  
  
  
 void OptimizationAlgorithm::from_XML(const tinyxml2::XMLDocument& document)
 {
     const tinyxml2::XMLElement* root_element = document.FirstChildElement("OptimizationAlgorithm");
  
     if(!root_element)
     {
         ostringstream buffer;
  
         buffer << "OpenNN Exception: OptimizationAlgorithm class.\n"
                << "void from_XML(const tinyxml2::XMLDocument&) method.\n"
                << "Optimization algorithm element is nullptr.\n";
  
         throw logic_error(buffer.str());
     }
  
   // Display
   {
      const tinyxml2::XMLElement* display_element = root_element->FirstChildElement("Display");
  
      if(display_element)
      {
         const string new_display_string = display_element->GetText();
  
         try
         {
            set_display(new_display_string != "0");
         }
         catch(const logic_error& e)
         {
            cerr << e.what() << endl;
         }
      }
   }
 }
  
  
  
 string OptimizationAlgorithm::object_to_string() const
 {
    ostringstream buffer;
  
    buffer << "Training strategy\n" 
           << "Display: " << display << "\n";
  
    return buffer.str();
 }
  
  
  
 Matrix<string> OptimizationAlgorithm::to_string_matrix() const
 {
     Matrix<string> string_matrix;
  
     return string_matrix;
 }
  
  
  
 void OptimizationAlgorithm::print() const
 {
    cout << object_to_string();
 }
  
  
  
 void OptimizationAlgorithm::save(const string& file_name) const
 {
    tinyxml2::XMLDocument* document = to_XML();
  
    document->SaveFile(file_name.c_str());
  
    delete document;
 }
  
  
  
 void OptimizationAlgorithm::load(const string& file_name)
 {
    set_default();
  
    tinyxml2::XMLDocument document;
  
    if(document.LoadFile(file_name.c_str()))
    {
       ostringstream buffer;
  
       buffer << "OpenNN Exception: OptimizationAlgorithm class.\n"
              << "void load(const string&) method.\n"
              << "Cannot load XML file " << file_name << ".\n";
  
       throw logic_error(buffer.str());
    }
  
    from_XML(document);
 }
  
  
  
 string OptimizationAlgorithm::Results::write_stopping_condition() const
 {
     switch(stopping_condition)
     {
     case MinimumParametersIncrementNorm:
     {
         return "Minimum parameters increment norm";
     }
     case MinimumLossDecrease:
     {
         return "Minimum loss decrease";
     }
     case LossGoal:
     {
         return "Loss goal";
     }
     case GradientNormGoal:
     {
         return "Gradient norm goal";
     }
     case MaximumSelectionErrorIncreases:
     {
         return "Maximum selection error increases";
     }
     case MaximumEpochsNumber:
     {
         return "Maximum number of iterations";
     }
     case MaximumTime:
     {
         return "Maximum training time";
     }
     }
  
     return string();
 }
  
  
  
 void OptimizationAlgorithm::Results::resize_training_history(const size_t& new_size)
 {
     training_error_history.resize(new_size);
     selection_error_history.resize(new_size);
 }
  
  
  
 string OptimizationAlgorithm::Results::object_to_string() const
 {
    ostringstream buffer;
  
    buffer << "% Results\n";
  
    // Loss history
  
    if(!training_error_history.empty())
    {
        buffer << "% Training error history:\n"
               << training_error_history << "\n";
    }
  
    // Selection loss history
  
    if(!selection_error_history.empty())
    {
        buffer << "% Selection loss history:\n"
               << selection_error_history << "\n";
    }
  
    return buffer.str();
 }
  
  
  
 void OptimizationAlgorithm::Results::save(const string&) const
 {
  
 }
  
  
  
 Matrix<string> OptimizationAlgorithm::Results::write_final_results(const int& precision) const
 {
    ostringstream buffer;
  
    Vector<string> names;
    Vector<string> values;
  
    // Final parameters norm
  
    names.push_back("Final parameters norm");
  
    buffer.str("");
    buffer << setprecision(precision) << final_parameters_norm;
  
    values.push_back(buffer.str());
  
    // Final loss
  
    names.push_back("Final training error");
  
    buffer.str("");
    buffer << setprecision(precision) << final_training_error;
  
    values.push_back(buffer.str());
  
    // Final selection error
  
 //   const LossIndex* loss_index_pointer = quasi_Newton_method_pointer->get_loss_index_pointer();
  
 //   if(loss_index_pointer->has_selection())
 //   {
        names.push_back("Final selection error");
  
        buffer.str("");
        buffer << setprecision(precision) << final_selection_error;
  
        values.push_back(buffer.str());
 //    }
  
    // Final gradient norm
  
    names.push_back("Final gradient norm");
  
    buffer.str("");
    buffer << setprecision(precision) << final_gradient_norm;
  
    values.push_back(buffer.str());
  
    // Final training rate
  
 //   names.push_back("Final training rate");
  
 //   buffer.str("");
 //   buffer << setprecision(precision) << final_learning_rate;
  
 //   values.push_back(buffer.str());
  
    // Epochs number
  
    names.push_back("Epochs number");
  
    buffer.str("");
    buffer << epochs_number;
  
    values.push_back(buffer.str());
  
    // Elapsed time
  
    names.push_back("Elapsed time");
  
    buffer.str("");
    buffer << write_elapsed_time(elapsed_time);
  
    values.push_back(buffer.str());
  
    // Stopping criteria
  
    names.push_back("Stopping criterion");
  
    values.push_back(write_stopping_condition());
  
    const size_t rows_number = names.size();
    const size_t columns_number = 2;
  
    Matrix<string> final_results(rows_number, columns_number);
  
    final_results.set_column(0, names, "name");
    final_results.set_column(1, values, "value");
  
    return(final_results);
 }
  
 }
  
  
 // OpenNN: Open Neural Networks Library.
 // Copyright(C) 2005-2019 Artificial Intelligence Techniques, SL.
 //
 // This library is free software; you can redistribute it and/or
 // modify it under the terms of the GNU Lesser General Public
 // License as published by the Free Software Foundation; either
 // version 2.1 of the License, or any later version.
 //
 // This library is distributed in the hope that it will be useful,
 // but WITHOUT ANY WARRANTY; without even the implied warranty of
 // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 // Lesser General Public License for more details.
  
 // You should have received a copy of the GNU Lesser General Public
 // License along with this library; if not, write to the Free Software
 // Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
