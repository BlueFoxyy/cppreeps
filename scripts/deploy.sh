#!/bin/bash

for i in "$@"; do
	case $i in
	-CMAKE_TOOLCHAIN_FILE=*)
		CMAKE_TOOLCHAIN_FILE="${i#*=}"
		shift
		;;
	-*)
		echo "Unknown option $i"
		exit 1
		;;
	*)
		;;
	esac
done

if [ "z${CMAKE_TOOLCHAIN_FILE}" = "z" ] ; then
	echo "Usage: $(basename "$0") -CMAKE_TOOLCHAIN_FILE=<emsdk-emscripten-cmake-file>"
	exit 1
fi

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
BASE_DIR="${SCRIPT_DIR%/*}"

cd "${BASE_DIR}" || exit 2

if [ ! -d build ] ; then
	echo "build/ directory does not exist, calling mkdir."
	mkdir build
fi

cd build || exit 2
cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE="${CMAKE_TOOLCHAIN_FILE}" ..
cmake --build .
