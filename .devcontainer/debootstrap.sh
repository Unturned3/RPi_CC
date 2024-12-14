#!/bin/bash

repo_url="http://deb.debian.org/debian"
release="bookworm"
arch="arm64"
sysroot_dir="$HOME/rpi3b-$release-$arch-sysroot"
packages=(
	libfmt-dev
	libfmt-doc
	libfmt9
)

# Convert to comma-separated string
packages=$(IFS=,; echo "${packages[*]}")

sudo debootstrap \
	--arch=$arch \
	--foreign \
	--include=$packages \
	$release \
	$sysroot_dir \
	$repo_url
	
