#include "student.h"
#include <string>

Student::Student() : id(0), name(""), age(0), score(0.0) {
    
}
Student::Student(int studentId, const std::string& studentName, int studentAge, double studentScore)
    : id(studentId), name(studentName), age(studentAge), score(studentScore) {
    
}