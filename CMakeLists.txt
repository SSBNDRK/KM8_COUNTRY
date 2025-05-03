cmake_minimum_required(VERSION 3.30)
project(KM8 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD      20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS     OFF)

find_package(CURL REQUIRED)

add_executable(KM8 main.cpp)

target_include_directories(KM8
        PRIVATE
        ${CURL_INCLUDE_DIRS}
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(KM8
        PRIVATE
        CURL::libcurl
)
