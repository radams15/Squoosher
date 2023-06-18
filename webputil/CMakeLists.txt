cmake_minimum_required(VERSION 3.0)
project(webputil)

set(CMAKE_CXX_STANDARD 11)

find_package(PkgConfig)
pkg_check_modules(WEBP libwebp REQUIRED)

add_library(webputil STATIC WebP.cpp)
add_subdirectory(imageio)

target_include_directories(webputil PUBLIC ${WEBP_INCLUDE_DIRS} imageio)
target_link_libraries(webputil PUBLIC ${WEBP_LIBRARIES} imageio)
