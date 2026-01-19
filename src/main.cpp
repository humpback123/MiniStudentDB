#include <iostream>
#include <string>
#include <sqlite3.h>
#include "database.h"

using namespace std;

Database* db = nullptr;

void showMenu() {
    cout << "\n===== Student DB =====" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Delete student" << endl;
    cout << "3. Update student" << endl;
    cout << "4. List students" << endl;
    cout << "0. Exit" << endl;
    cout << "======================" << endl;
    cout << "Please enter your choice (0-4): ";
}

void addStudent()
{
    cout << "\n--- Add Student ---" << endl;
    
    string name;
    int age;
    double score;
    
    cout << "Enter student name: ";
    cin.ignore();  
    getline(cin, name);
    
    cout << "Enter student age: ";
    cin >> age;
    
    cout << "Enter student score: ";
    cin >> score;
    
    string sql = "INSERT INTO student (name, age, score) VALUES ('" + 
                 name + "', " + to_string(age) + ", " + to_string(score) + ");";
    
    if (db->execute(sql)) 
    {
        cout << "Student added successfully!" << endl;
    } 
    else 
    {
        cout << "Failed to add student!" << endl;
    }
}

void deleteStudent()
{
    cout << "\n--- Delete Student ---" << endl;
    
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;
    
    cout << "Are you sure? (y/n): ";
    char confirm;
    cin >> confirm;
    
    if (confirm == 'y' || confirm == 'Y') 
    {
        string sql = "DELETE FROM student WHERE id = " + to_string(id) + ";";
        
        if (db->execute(sql)) 
        {
            cout << "Student deleted successfully!" << endl;
        } 
        else 
        {
            cout << "Failed to delete student!" << endl;
        }
    } 
    else 
    {
        cout << "Operation cancelled." << endl;
    }
}

void updateStudent()
{
    cout << "\n--- Update Student ---" << endl;
    
    int id;
    cout << "Enter student ID to update: ";
    cin >> id;
    
    string name;
    int age;
    double score;
    
    cout << "Enter new name: ";
    cin.ignore(); 
    getline(cin, name);
    
    cout << "Enter new age: ";
    cin >> age;
    
    cout << "Enter new score: ";
    cin >> score;
    
    string sql = "UPDATE student SET name = '" + name + 
                 "', age = " + to_string(age) + 
                 ", score = " + to_string(score) + 
                 " WHERE id = " + to_string(id) + ";";
    
    if (db->execute(sql)) 
    {
        cout << "Student updated successfully!" << endl;
    } 
    else 
    {
        cout << "Failed to update student!" << endl;
    }
}

void listStudents()
{
    sqlite3* sqlite_db;
    if (sqlite3_open("data/student.db", &sqlite_db) != SQLITE_OK) 
    {
        cout << "Error: Cannot open database!" << endl;
        return;
    }
    
    const char* sql = "SELECT * FROM student ORDER BY id;";
    sqlite3_stmt* stmt;
    
    if (sqlite3_prepare_v2(sqlite_db, sql, -1, &stmt, nullptr) != SQLITE_OK) 
    {
        cout << "Error: Failed to prepare SQL query!" << endl;
        sqlite3_close(sqlite_db);
        return;
    }
    
    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        double score = sqlite3_column_double(stmt, 3);
        
        cout << id << " " << name << " " << age << " " << score << endl;
    }
    
    sqlite3_finalize(stmt);
    sqlite3_close(sqlite_db);
}

int main()
{
    db = new Database("data/student.db");
    if (!db->isOpen()) {
        cout << "Failed to open database! Exiting..." << endl;
        delete db;
        return 1;
    }
    
    int choice;
    while(true)
    {
        showMenu();
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                cout << "\n[Add Student] Selected" << endl;
                addStudent();
                break;
            case 2:
                cout << "\n[Delete Student] Selected" << endl;
                deleteStudent();
                break;
            case 3:
                cout << "\n[Update Student] Selected" << endl;
                updateStudent();
                break;
            case 4:
                cout << "\n[List Students] Selected" << endl;
                listStudents();
                break;
            case 0:
                cout << "\n[Exit] Thank you for using Student DB!" << endl;
                delete db;
                return 0;
            default:
                cout << "\n[Error] Invalid choice! Please enter 0-4." << endl;
                break;
        }
    }
}