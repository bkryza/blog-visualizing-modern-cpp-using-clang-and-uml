cmake_minimum_required(VERSION 3.28)
project(code)

set(CMAKE_CXX_STANDARD 20)

option(LINK_LLVM_SHARED "Should LLVM be linked using shared libraries" ON)
set(LLVM_VERSION CACHE STRING "Major LLVM version to use (e.g. 15)")
set(LLVM_CONFIG_PATH CACHE STRING "Path to llvm-config binary")
set(CMAKE_PREFIX CACHE STRING "Path to custom cmake modules")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_PREFIX}")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

#
# Setup LLVM
#
include(LLVMSetup)

link_directories(${LLVM_LIBRARY_DIR})

add_subdirectory(simple_app)

add_executable(code main.cpp
                    basic_example.cpp
                    smart_pointer_relationships.cpp
                    template_specializations.cpp
                    concepts.cpp
                    basic_sequence.cpp
                    factorial_sequence.cpp
                    advanced_sequence.cpp
                    namespace_package.cpp
                    include_diagram/src/include_diagram.cpp
                    deduced_context.cpp
                    variadic_print.cpp
                    type_list.cpp
                    recursive_list.cpp
                    nonvirtual_visitor_pattern.cpp)

target_link_libraries(code simple_app)

add_library(decl_ids decl_ids1.cpp decl_ids2.cpp)
target_link_libraries(decl_ids ${LIBTOOLING_LIBS})
