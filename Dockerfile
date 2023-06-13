FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
    gcc g++ make cmake \
    libwxgtk3.0-gtk3-dev \
    fuse curl file \
    libwebp-dev libtiff-dev libjpeg-dev libpng-dev

RUN curl -L https://github.com/linuxdeploy/linuxdeploy/releases/download/1-alpha-20220822-1/linuxdeploy-x86_64.AppImage -o /opt/linuxdeploy && chmod +x /opt/linuxdeploy

RUN /opt/linuxdeploy --appimage-extract

WORKDIR /app

ENV LINUXDEPLOY=/squashfs-root/AppRun

ENTRYPOINT ["bash", "/app/build.sh"]
