cmake_minimum_required(VERSION 3.24)
project(squoosher)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig)
pkg_check_modules(WEBP libwebp REQUIRED)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include( "${wxWidgets_USE_FILE}" )

add_subdirectory(imageio)

add_executable(squoosher SquooshApp.cpp SquooshApp.h Squoosh.cpp Squoosh.h MainFrame.cpp MainFrame.h ImageController.cpp ImageController.h FileDropTarget.cpp FileDropTarget.h ConversionQueue.cpp ConversionQueue.h ItemPanel.cpp ItemPanel.h)

target_include_directories(squoosher PRIVATE ${WEBP_INCLUDE_DIRS} imageio)
target_link_libraries(squoosher PRIVATE ${wxWidgets_LIBRARIES} ${WEBP_LIBRARIES} imageio)
