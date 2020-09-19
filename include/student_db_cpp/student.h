// student.h
#include<string>
#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H
#include "student.h"
using namespace std;

class Student
{
   private:
    int studentId;
    string studentName;
    int studentGrade;
  public:
     Student::Student(int id, string name, int grade)
    {
       studentId=id;
       studentName=name;
       studentGrade=grade;
    };
    Student::Student(){ studentGrade = 0;};
    int GetId(){return studentId;};
    void GetName(){
         cout << studentName;
         };
    int GetGrade(){return studentGrade;};
};
#endif
