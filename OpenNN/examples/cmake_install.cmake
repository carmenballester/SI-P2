# Install script for directory: /home/carmenballester/Escritorio/Practica2/OpenNN/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_function_regression/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/simple_pattern_recognition/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/airfoil_self_noise/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/breast_cancer/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/iris_plant/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/leukemia/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/logical_operations/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/pima_indians_diabetes/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/urinary_inflammations_diagnosis/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/yacht_hydrodynamics_design/cmake_install.cmake")
  include("/home/carmenballester/Escritorio/Practica2/OpenNN/examples/yacht_hydrodynamics_production/cmake_install.cmake")

endif()

