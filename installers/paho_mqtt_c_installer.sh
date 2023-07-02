cmake -S ./modules/paho_mqtt_c -B ./dependencies/paho_mqtt_c -DCMAKE_INSTALL_PREFIX="./install" -DCMAKE_BUILD_TYPE=$1 -DPAHO_BUILD_STATIC=ON
cmake --build ./dependencies/paho_mqtt_c --target install