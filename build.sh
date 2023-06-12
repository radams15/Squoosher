#!/bin/bash

BUILDDIR=builddir
LINUXDEPLOY=/home/rhys/Downloads/linuxdeploy-x86_64.AppImage

rm -rf $BUILDDIR
mkdir -p $BUILDDIR

cd $BUILDDIR
cmake .. -DCMAKE_INSTALL_PREFIX=/usr || exit $?
make -j`nproc` || exit $?
make install DESTDIR=AppDir

$LINUXDEPLOY --appdir AppDir -d ../res/squoosher.desktop -i ../res/squoosher.png --output appimage