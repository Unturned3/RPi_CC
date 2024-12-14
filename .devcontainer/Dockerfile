FROM mcr.microsoft.com/devcontainers/cpp:debian-12

#ARG arch=arm64
#ARG release=bookworm

COPY sbuildrc /home/vscode/.sbuildrc
COPY debootstrap.sh /home/vscode/debootstrap.sh

RUN \
	apt-get update && \
	export DEBIAN_FRONTEND=noninteractive && \
	apt-get -y install --no-install-recommends \
		file neovim \
		clangd clang-format \
		debootstrap \
		gcc-aarch64-linux-gnu \
		g++-aarch64-linux-gnu \
		gfortran-aarch64-linux-gnu

# Orbstack has built-in support for qemu-arm64. If you're using, say, Docker Desktop,
# then you need to install qemu-user-static (uncomment the lines below). qemu-arm64
# is used for chrooting into the debootstrap sysroot.
#RUN apt-get -y install --no-install-recommends \
#	qemu-user-static

# You can write multiple --include="..." lines to install more packages in the sysroot.
RUN sudo debootstrap \
	--arch=arm64 \
	--foreign \
	--include="libfmt-dev,libfmt-doc,libfmt9" \
	bookworm \
	/home/vscode/rpi3b-bookworm-arm64 \
	"http://deb.debian.org/debian"

RUN sudo chroot /home/vscode/rpi3b-bookworm-arm64 \
	/debootstrap/debootstrap --second-stage

#RUN sudo chroot /home/vscode/rpi3b-bookworm-arm64 \
#	apt install -y \
#		libgpiod-dev \

# Install any vcpkg ports
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"
