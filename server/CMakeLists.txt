cmake_minimum_required(VERSION 3.27)
project(server)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Network REQUIRED)

add_executable(server
        main.cpp
        TcpEchoServer.cpp
        main.h
        TcpEchoServer.h
)

target_link_libraries(server
Qt6::Core
Qt6::Network
)
