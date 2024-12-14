cmake_minimum_required(VERSION 3.16)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(hello VERSION 0.1 LANGUAGES C CXX)

find_package(fmt CONFIG REQUIRED)

add_executable(fmt_test fmt_test.cpp)

target_link_libraries(fmt_test PRIVATE fmt::fmt)

include(GNUInstallDirs)
install(TARGETS fmt_test
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})


project(blink VERSION 0.1 LANGUAGES CXX)

add_executable(blink blink.cpp)
target_link_libraries(blink PRIVATE gpiodcxx)
