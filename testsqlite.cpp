#include <sqlite3.h>
#include <iostream>

int callback(void *NotUsed, int argc, char **argv, char **azColName);

int main() {
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }
  
    std::string sql = "CREATE TABLE IF NOT EXISTS users (   \
                 id INTEGER PRIMARY KEY AUTOINCREMENT,  \
                  name TEXT NOT NULL,  \
                 age INTEGER NOT NULL);";

    rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    } else {
        std::cout << "Table created successfully" << std::endl;
    }

    sql = "INSERT INTO users (name, age) VALUES ('John Doe', 30);";
    rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    } else {
        std::cout << "Record created successfully" << std::endl;
    }
  

    sql = "SELECT * FROM users;"; 
    char *zErrMsg = 0;
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    }

    sql = "SELECT * FROM users;";
    char **result;
    int rowCount, columnCount;
    rc = sqlite3_get_table(db, sql.c_str(), &result, &rowCount, &columnCount, 0);
    std::cout << "Query results:" << std::endl;
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < columnCount; ++j) {
            std::cout << result[i * columnCount + j] << " ";
        }
        std::cout << std::endl;
    }    
    
    sqlite3_close(db);
    return 0;
}
int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << std::endl;
    }
    std::cout << std::endl;
    return 0;
}