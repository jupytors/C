cmake_minimum_required(VERSION 3.18)
 
project(CPP)

add_executable(main main.cpp)
#add_executable(main testsqlite.cpp)
target_compile_features(main PRIVATE cxx_std_17)
include_directories("./include/")


target_link_libraries(main  ${CMAKE_SOURCE_DIR}/lib/sqlite3.so) 
#target_link_libraries(main  -L/cloudide/workspace/C/include/sqlite3_lib/lib/ -llibsqlite3.so)

#link_directories("./include/lib/")