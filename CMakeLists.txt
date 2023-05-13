cmake_minimum_required(VERSION 3.5)

project(test_work)

add_executable(test_work 
    main.cpp
    file.cpp
    system.cpp
)
set(CMAKE_CXX_FLAGS "-pthread")
set_target_properties(test_work PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)