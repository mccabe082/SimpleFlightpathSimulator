REM Run me on windows to install to ./bin
pushd build
	cmake ..
	cmake --build . --config Debug
	cmake --install . --config Debug
popd
