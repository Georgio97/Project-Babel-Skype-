project(babel)
cmake_minimum_required(VERSION 2.8.12)

# Check OS
if (CMAKE_HOST_WIN32)
    set(WINDOWS 1)
elseif (CMAKE_HOST_APPLE)
    set(MACOS 1)
elseif (CMAKE_HOST_UNIX)
    set(LINUX 1)
endif ()

# Si c'est linux
if (LINUX)
    add_definitions("-fPIC")
    add_custom_target(babel)
    add_custom_command(TARGET babel
            PRE_BUILD
            COMMAND /bin/sh ${PROJECT_SOURCE_DIR}/conan_installer.sh)
endif ()

if (WINDOWS)

endif ()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Conan install
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Config et import de boost
SET(Boost_USE_MULTITHREAD ON)
set(Boost_USE_STATIC_LIBS OFF CACHE BOOL "use static libraries from Boost")
set(Boost_USE_STATIC_RUNTIME OFF)
set(Boost_ALL_DYN_LINK ON)
find_package(Boost COMPONENTS filesystem system thread regex REQUIRED)

IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS} ${CMAKE_INCLUDE_PATH})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF (Boost_FOUND)

SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

# Config et import de Qt
find_package(Qt5 COMPONENTS Widgets Core Gui Network REQUIRED)

# Definition des fichiers des libs
file(GLOB_RECURSE LIBS_SRC libs/*.cpp)
file(GLOB_RECURSE LIBS_INCL libs/*.hpp)

# Definition des fichiers du client
file(GLOB_RECURSE CLIENT_SRC client/*.cpp)
file(GLOB_RECURSE CLIENT_INCL client/*.h client/MainWindow/TcpManager/*.h)
file(GLOB_RECURSE UI_FILES client/GUI/mainwindow.ui)
qt5_wrap_ui(UI_HEADERS client/GUI/mainwindow.ui)

# Definition de l'excécutable et linkage des libs
ADD_EXECUTABLE(babel_client ${CLIENT_SRC} ${CLIENT_INCL} ${LIBS_SRC} ${LIBS_INCL} ${UI_HEADERS})
TARGET_LINK_LIBRARIES(babel_client ${CONAN_LIBS} Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)

# Definition des fichiers du server
file(GLOB_RECURSE SERVER_SRC server/*.cpp)
file(GLOB_RECURSE SERVER_INCL server/*.hpp)

# Definition de l'excécutable et linkage des libs
ADD_EXECUTABLE(babel_server ${SERVER_SRC} ${SERVER_INCL} ${LIBS_SRC} ${LIBS_INCL})
TARGET_LINK_LIBRARIES(babel_server ${USED_LIBS} ${CONAN_LIBS})