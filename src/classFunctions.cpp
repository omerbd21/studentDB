#include <string>
#include "../include/student_db_cpp/class.h"
using namespace std;
void addClass(Class** classes)
{
       int classGrade;
       cout << "Please enter the grade of the class:" << endl;
       cin >> classGrade;
       if (classGrade > 12 or classGrade < 1)
      {
        cout << "The class doesn't exist" << endl;
        return;
      }
       else if ((*classes)[classGrade-1].GetGrade() != 0)
       {
         cout << "There is already a class in that age group." << endl;
       }
       else
       {
           *classes[classGrade-1] = Class(classGrade);
       }
};
void getClass(Class** classes)
{
     int classNumber;
     cout << "Please enter a number of class." << endl;
     cin >> classNumber;
     if (sizeof(classes)/ sizeof(classes[0]) < classNumber)
     {
      cout << "The class doesn't exist" << endl;
      return;
     };
     int classAction;
     cout << "Please enter a number for the action you want." << endl;
     cout << "1. Get Grade.\n 2. Get Students" << endl;
     cin >> classAction;
     if (classAction == 1)
     {
          cout << (*classes)[classNumber-1].GetGrade() << endl;
     }
     else
     {
         (*classes)[classNumber-1].GetStudents();
     }
};
void addStudentToClass(Class** classes, Student** students)
{
     int studentNumInSchool;
     int classNumber;
     cout << "Please enter a number of class." << endl;
     cin >> classNumber;
     if (sizeof(classes)/ sizeof(classes[0]) < classNumber)
     {
      cout << "The class doesn't exist" << endl;
      return;
     };
     cout << "Please enter the number of student you want to add to the class." << endl;
     cin >> studentNumInSchool;
     (*classes)[classNumber-1].AddStudent(*(students)[studentNumInSchool]);
};
