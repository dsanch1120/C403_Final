cmake_minimum_required(VERSION 3.15)
project(theOfficeData)

set(CMAKE_CXX_STANDARD 14)

add_executable(theOfficeData main.cpp TransferScript.cpp TransferScript.h cmake-build-debug/TransferRatings.cpp cmake-build-debug/TransferRatings.h)