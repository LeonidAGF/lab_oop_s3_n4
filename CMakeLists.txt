cmake_minimum_required(VERSION 3.20)

project(laba_n4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(laba_n4_lib
    src/set.cpp
    src/3D.cpp
)

target_include_directories(laba_n4_lib PUBLIC
    src
)

add_executable(laba_oop_s3_n4
    main.cpp
)

target_link_libraries(laba_oop_s3_n4
    laba_n4_lib
)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(laba_n4_tests
    tests/test.cpp
)

target_link_libraries(laba_n4_tests
    laba_n4_lib
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(laba_n4_tests)