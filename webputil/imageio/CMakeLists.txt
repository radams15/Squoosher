cmake_minimum_required(VERSION 3.0)
project(imageio)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig)
pkg_check_modules(JPEG libjpeg REQUIRED)
pkg_check_modules(TIFF libtiff-4)
pkg_check_modules(PNG libpng REQUIRED)
pkg_check_modules(WEBP libwebp REQUIRED)
pkg_check_modules(WEBPDMUX libwebpdemux REQUIRED)

add_library(imageio STATIC image_dec.c image_enc.c imageio_util.c jpegdec.c metadata.c pngdec.c pnmdec.c tiffdec.c webpdec.c wicdec.c defs.h)

if(TIFF_INCLUDE_DIRS)
    message("Using tiff!")
    target_compile_definitions(imageio PRIVATE WEBP_HAVE_TIFF=1)
endif()

target_compile_definitions(imageio PRIVATE WEBP_HAVE_JPEG=1 WEBP_HAVE_PNG=1)
target_include_directories(imageio PRIVATE ${WEBP_INCLUDE_DIRS} ${WEBPDEMUX_INCLUDE_DIRS} ${JPEG_INCLUDE_DIRS} ${PNG_INCLUDE_DIRS} ${TIFF_INCLUDE_DIRS})
target_link_libraries(imageio PRIVATE ${WEBP_LIBRARIES} ${WEBPDEMUX_LIBRARIES} ${JPEG_LIBRARIES} ${PNG_LIBRARIES} ${TIFF_LIBRARIES} tiff webpdemux)
