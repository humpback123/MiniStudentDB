#include "database.h"
#include <iostream>

Database::Database(const std::string& filename) : db(nullptr), filename(filename) {
    int rc = sqlite3_open(filename.c_str(), &db);
    
    if (rc != SQLITE_OK) {
        std::cerr << "Error: Cannot open database '" << filename << "': " 
                  << sqlite3_errmsg(db) << std::endl;
        return;
    }
    
    std::cout << "Database opened successfully: " << filename << std::endl;
    
    if (!initStudentTable()) {
        std::cerr << "Error: Failed to initialize student table!" << std::endl;
    }
}

Database::~Database() {
    if (db != nullptr) {
        sqlite3_close(db);
        db = nullptr;
        std::cout << "Database connection closed." << std::endl;
    }
}

bool Database::execute(const std::string& sql) {
    if (db == nullptr) {
        std::cerr << "Error: Database not opened!" << std::endl;
        return false;
    }
    
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    
    if (rc != SQLITE_OK) {
        std::cerr << "SQL Error: " << errMsg << std::endl;
        std::cerr << "Failed SQL: " << sql << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    
    return true;
}

bool Database::initStudentTable() {
    std::string createTableSQL = 
        "CREATE TABLE IF NOT EXISTS student ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "age INTEGER,"
        "score REAL"
        ");";
    
    return execute(createTableSQL);
}

// 获取错误信息
std::string Database::getError() const {
    if (db == nullptr) {
        return "Database not opened";
    }
    return sqlite3_errmsg(db);
}

// 检查数据库是否打开
bool Database::isOpen() const {
    return db != nullptr;
}