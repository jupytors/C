#include <sqlite3.h>
#include <iostream>

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }
  
    char *sql = "CREATE TABLE IF NOT EXISTS users (   \
                 id INTEGER PRIMARY KEY AUTOINCREMENT,  \
                  name TEXT NOT NULL,  \
                 age INTEGER NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    sql = "INSERT INTO users (name, age) VALUES ('John Doe', 30);";
    rc = sqlite3_exec(db, sql, 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    } else {
        std::cout << "Record created successfully" << std::endl;
    }

    sqlite3_close(db);
    return 0;
}