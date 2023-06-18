cmake_minimum_required(VERSION 3.10)
project(squoosher)

set(CMAKE_CXX_STANDARD 11)
set(VERSION 1.1)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include( "${wxWidgets_USE_FILE}" )

add_subdirectory(webputil)

add_executable(squoosher SquooshApp.cpp SquooshApp.h Squoosh.cpp Squoosh.h MainFrame.cpp MainFrame.h FileDropTarget.cpp FileDropTarget.h ConversionQueue.cpp ConversionQueue.h ItemPanel.cpp ItemPanel.h ConversionThread.cpp ConversionThread.h)

target_compile_definitions(squoosher PRIVATE IMAGE_PREVIEWS SQUOOSHER_VERSION="${VERSION}")
target_include_directories(squoosher PRIVATE webputil)
target_link_libraries(squoosher PRIVATE ${wxWidgets_LIBRARIES} webputil)

install(TARGETS squoosher DESTINATION bin)
install(FILES res/squoosher.desktop res/squoosher.png DESTINATION share/applications/)