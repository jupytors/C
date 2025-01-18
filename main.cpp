#include <crow.h>

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello, World!";
    });

    app.port(18080).run();
} 
/**

cd ..
git clone  https://github.com/CrowCpp/Crow.git 
git clone https://github.com/chriskohlhoff/asio.git
git clone https://github.com/boostorg/boost.git
cd Crow
mkdir build
cd build  
cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF -DASIO_INCLUDE_DIR=../../asio/asio/include -DCMAKE_INSTALL_PREFIX=../../C/include
make install
 
/cloudide/workspace/C/

cmakelist.txt:
cmake_minimum_required(VERSION 3.18)
 
project(CPP)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_17)
include_directories("./include/include/")
include_directories("/cloudide/workspace/asio/asio/include/")
link_directories("./include/lib/")

 wget https://www.sqlite.org/2021/sqlite-autoconf-3360000.tar.gz 
 
 ./configure --prefix=/home/sqlite3_lib
 * 
 */