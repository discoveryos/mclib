#!/bin/sh
# Simplified configure script
prefix=/usr/local/mclib
CC=gcc
ARCH=x86_64

# Simple argument parsing (--prefix=, --arch=)
for arg ; do
    case "$arg" in
        --prefix=*) prefix=${arg#*=} ;;
        --arch=*) ARCH=${arg#*=} ;;
    esac
done

# Validate arch and generate config.mak
if [ ! -d "arch/$ARCH" ]; then
    echo "Error: Architecture '$ARCH' not supported."
    exit 1
fi

cat << EOF > config.mak
PREFIX = $prefix
ARCH = $ARCH
CC = $CC
EOF
echo "Configured for $ARCH."
