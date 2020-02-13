cmake_minimum_required(VERSION 3.5)

project(client LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Network REQUIRED)

include_directories(MainWindow/SettingsWindow)
include_directories(MainWindow/TcpManager)
include_directories(MainWindow/UdpManager)

set(SOURCES main.cpp
TcpManager/tcpmanager.h
UdpManager/udpmanager.h
MainWindow/mainwindow.h
MainWindow/mainwindow.cpp
UdpManager/udpmanager.cpp
TcpManager/tcpmanager.cpp
MainWindow/mainwindow.ui)

add_executable(client ${SOURCES})

target_link_libraries(client PRIVATE Qt5::Widgets)
target_link_libraries(client PRIVATE Qt5::Network)
