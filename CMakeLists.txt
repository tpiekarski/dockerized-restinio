cmake_minimum_required(VERSION 3.13)

project(dockerized-restinio 
  VERSION 0.1
)

set(SOURCE "src/")
set(INCLUDE "include/")

include_directories(${INCLUDE})
add_executable(
  dockerized-restinio
  ${SOURCE}/controller/readyness-controller.cpp
  ${SOURCE}/dockerized-restinio.cpp
  ${INCLUDE}/controller/readyness-controller.h
  ${INCLUDE}/router.h
)


find_package(Threads)
find_package(fmt REQUIRED)
find_package(unofficial-http-parser REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)
find_package(restinio REQUIRED)

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
