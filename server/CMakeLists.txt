cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE HDW_MONITOR_HDRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "include/*.hpp")
file(GLOB_RECURSE HDW_MONITOR_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "lib/*.cpp")

# Set the output directory for the executable
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
set(CMAKE_INSTALL_BINDIR ${CMAKE_INSTALL_PREFIX}/bin)

# Build the executable
add_executable(server_monitor ${HDW_MONITOR_HDRS} ${HDW_MONITOR_SRCS})
target_include_directories(server_monitor PUBLIC "./include" "${PROJECT_SOURCE_DIR}/install/include")
target_link_directories(server_monitor PUBLIC "${PROJECT_SOURCE_DIR}/install/lib")
target_link_libraries(server_monitor PUBLIC jsoncpp paho-mqtt3a paho-mqtt3c mongoc-static-1.0)

# Install the executable to the specified directory
install(TARGETS server_monitor DESTINATION ${CMAKE_INSTALL_BINDIR})