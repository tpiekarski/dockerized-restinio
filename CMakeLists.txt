# 
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/. 
#

cmake_minimum_required(VERSION 3.13)

project(dockerized-restinio 
  VERSION 0.1
)

set(SOURCE "src")
set(INCLUDE "include")
set(TEST "test")

include_directories(${INCLUDE})
add_executable(
  dockerized-restinio

  ${SOURCE}/controller/readyness-controller.cpp
  ${SOURCE}/dockerized-restinio.cpp
  ${SOURCE}/options.cpp

  ${INCLUDE}/controller/controller-interface.h
  ${INCLUDE}/controller/readyness-controller.h
  ${INCLUDE}/dispatcher.h
  ${INCLUDE}/options.h
)

find_package(Threads)
find_package(fmt REQUIRED)
find_package(unofficial-http-parser REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem program_options unit_test_framework)
find_package(restinio REQUIRED)

include_directories (${Boost_INCLUDE_DIRS})

enable_testing()
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${TEST}/*.cpp)
foreach(testSrc ${TEST_SRCS})
  get_filename_component(testName ${testSrc} NAME_WE)
  add_executable(${testName} ${testSrc})
  target_link_libraries(${testName} ${Boost_LIBRARIES})
  set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin)
  add_test(
    NAME ${testName} 
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin 
    COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName}
  )
endforeach(testSrc)

target_link_libraries(
  dockerized-restinio
  PRIVATE
    ${CMAKE_THREAD_LIBS_INIT}
    fmt::fmt
    unofficial::http_parser::http_parser
    ${Boost_LIBRARIES}
    restinio::restinio
)

set_property(TARGET dockerized-restinio PROPERTY CXX_STANDARD 14)
