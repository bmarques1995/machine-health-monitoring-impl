cmake -S ./modules/jsoncpp -B ./dependencies/jsoncpp -DCMAKE_INSTALL_PREFIX="./install" -DCMAKE_BUILD_TYPE=$1
cmake --build ./dependencies/jsoncpp --target install