// course.h
using namespace std;
#include "student.h"
#include <iostream>
#ifndef COURSE_H
#define COURSE_H
#include "course.h"
class Course
{
private:
    string courseName;
    Student students[40];
    int studentNumber;
public:
    Course(string name)
    {
       courseName=name;
       studentNumber = 0;
    };
    string GetName()
    {
           return courseName;
    };
    void GetStudents()
    {
        for (int studentIndex=0; studentIndex< studentNumber; studentIndex++)
       {
           cout << "ID: " <<students[studentIndex].GetId();
           cout << " Name: "; 
           students[studentIndex].GetName();
           cout << "\n";
       }  
    };
    void AddStudent(Student student)
    {
         students[studentNumber] = student;
         studentNumber++;
    };
};
#endif
