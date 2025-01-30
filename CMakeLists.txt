cmake_minimum_required(VERSION 3.16)

project(TForm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TForm main.cpp
    include/Screen/ScreenBase.hpp
    include/Char/CharBase.hpp
    include/Screen/ScreenRender.hpp
    src/Screen/Refresh.cpp
    src/Screen/Print.cpp
    src/Screen/Put.cpp)

include_directories(include)

include(GNUInstallDirs)
install(TARGETS TForm
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
