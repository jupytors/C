#include <crow.h>
// https://github.com/jupytors/C.git  
int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello, World!";
    });

    app.port(18080).run();
} 
