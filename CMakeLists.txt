cmake_minimum_required(VERSION 3.24.1)
project(juce-libtorch)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

if (NOT DEFINED TORCH_DIR) 
    message(FATAL_ERROR "TORCH_DIR not specified")
endif()

list(APPEND CMAKE_MODULE_PATH ${TORCH_DIR}/share/cmake)
include(Torch/TorchConfig)

add_subdirectory(src)
add_subdirectory(tests)