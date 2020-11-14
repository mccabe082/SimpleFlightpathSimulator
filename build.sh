#!/bin/bash

cd "$(dirname "$0")"

rm -rf build
mkdir build
pushd build
	cmake ..
	cmake --build . --config Debug
	cmake --install . --config Debug
popd

pushd build
ctest -C Debug -VV
popd
