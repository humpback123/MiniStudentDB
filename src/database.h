#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

class Database {
private:
    sqlite3* db;          
    std::string filename; 
    
public:
    Database(const std::string& filename);
    
    ~Database();
    
    bool execute(const std::string& sql);
    
    std::string getError() const;
    
    bool isOpen() const;
    
private:
    bool initStudentTable();
};

#endif 