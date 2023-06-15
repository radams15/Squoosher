FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive
ENV WXVER=3.2.2.1

RUN apt-get update && apt-get install -y \
    gcc g++ make cmake build-essential \
    libgtk-3-dev \
    fuse curl file \
    libwebp-dev libtiff-dev libjpeg-dev libpng-dev


RUN curl -L https://github.com/wxWidgets/wxWidgets/releases/download/v${WXVER}/wxWidgets-${WXVER}.tar.bz2 -o - | tar xjf -
WORKDIR wxWidgets-${WXVER}

RUN apt-get install -y qtbase5-dev

RUN mkdir -p build
WORKDIR build

RUN ../configure \
    --with-qt \
    --disable-shared \
    --enable-unicode

RUN make -j`nproc`
RUN make install && ldconfig

WORKDIR /

RUN curl -L https://github.com/linuxdeploy/linuxdeploy/releases/download/1-alpha-20220822-1/linuxdeploy-x86_64.AppImage -o /opt/linuxdeploy \
    && chmod +x /opt/linuxdeploy \
    && /opt/linuxdeploy --appimage-extract

WORKDIR /app

ENV LINUXDEPLOY=/squashfs-root/AppRun

ENTRYPOINT ["bash", "/app/build.sh"]
