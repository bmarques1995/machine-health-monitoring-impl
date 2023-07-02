cmake -S ./modules/mongo_c -B ./dependencies/mongo_c -DCMAKE_INSTALL_PREFIX="./install" -DCMAKE_BUILD_TYPE=$1
cmake --build ./dependencies/mongo_c --target install