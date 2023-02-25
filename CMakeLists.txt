cmake_minimum_required(VERSION 3.24.1)
project(juce-libtorch VERSION 0.01)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

## Setup for libtorch
if (NOT DEFINED TORCH_DIR) 
    message(FATAL_ERROR "TORCH_DIR not specified")
endif()

list(APPEND CMAKE_MODULE_PATH ${TORCH_DIR}/share/cmake)
include(Torch/TorchConfig)

## Setup for JUCE
if (NOT DEFINED JUCE_DIR) 
    message(FATAL_ERROR "JUCE_DIR not specified")
endif()
add_subdirectory(${JUCE_DIR} ${JUCE_DIR}/build)

add_subdirectory(src)
add_subdirectory(tests)