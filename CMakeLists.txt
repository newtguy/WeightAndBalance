cmake_minimum_required(VERSION 3.16)
project(WeightAndBalance)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(WeightAndBalance
        main.cpp
        Airplane.cpp
        AirplaneLoader.cpp
        WeightAndBalance.cpp
)