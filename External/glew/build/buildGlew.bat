mkdir MyBuild
pushd MyBuild
cmake -DCMAKE_INSTALL_PREFIX=../../../Windows -G "Visual Studio 15 2017 Win64" ../cmake
cmake --build . --config release --target install
popd