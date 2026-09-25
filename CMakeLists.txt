cmake_minimum_required(VERSION 3.10)
project(sortlib_project CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Библиотека сортировок (статическая)
add_library(sortlib STATIC src/sortlib.cpp)
target_include_directories(sortlib PUBLIC include)

# Программа-потребитель
add_executable(myprog app/main.cpp)
target_link_libraries(myprog PRIVATE sortlib)