#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    int id;           
    std::string name; 
    int age;        
    double score;   

public:
    Student();
    
    Student(int studentId, const std::string& studentName, int studentAge, double studentScore);
};

#endif