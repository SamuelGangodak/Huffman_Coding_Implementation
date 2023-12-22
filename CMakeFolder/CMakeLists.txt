cmake_minimum_required(VERSION 3.26)
project(Winter_W23__Project C)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES "../Main_Folder/mainFile.c"
        ../Implementation/Bitstream.c 
        ../Implementation/charMap.c 
        ../Implementation/Heap_function.c 
        ../Implementation/Node.c 
        ../Implementation/String_builder.c)
file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}")

add_executable(target ${SOURCES})



