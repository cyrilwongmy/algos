cmake_minimum_required(VERSION 3.23)
project(algos)

set(CMAKE_CXX_STANDARD 20)

# Find all .cpp files and add them to executable
file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
    add_executable (${exe} ${file})
    message (\ \ \ \ --\ src/${exe}.cpp\ will\ be\ compiled\ to\ bin/${exe})
endforeach ()
