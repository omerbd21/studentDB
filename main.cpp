#include <iostream>
#include "include/student_db_cpp/class.h"
#include "include/student_db_cpp/course.h"
#include "src/common.cpp"
using namespace std;

int main()
{
    string OBJECTS[] = {"student", "class", "course"};
    string ACTIONS[] = {"CREATE", "GET", "ADD"};
    if (argc != 3 || in_array(argv[1], OBJECTS))
     {
          std::cerr << "Usage: main [Object] [Action]"
                              << std::endl;
          return 0;
     }
    
    char* object = argv[1];
    char* action = argv[2];
    Student* students;
    Class classes[12];
    Course* courses;
    int courseNumber = 0;
    int studentNumber = 0;
    if (object == OBJECTS[0])
    {
      if (action == ACTIONS[0])
      {
        int studentId;
        string studentName;
        int studentClass;
        cout << "Please enter an ID, a name and a class:" << endl;
        cin >> studentId;
        getline(cin, studentName);
        cin >> studentClass;
        students[studentNumber] = Student(studentId, studentName, stduentClass);
      }
      else if (action == ACTIONS[1])
      {
          int studentId;
          int getAction;
          cout << "Please enter the number of the student:" << endl;
          cin >> studentNum;
          cout << "Please enter the number for the GET action you want." << endl;
          cout << "1. Get ID\n2. Get Name\n3. Get Grade." << endl;
          cin >> getAction;
          if (getAction == 1)
          {
            students[studentNum].GetId();
          }
          else if (getAction == 2)
          {
               students[studentNum].GetName();
          }
          else
          {
              students[studentNum].GetGrade();
          };
      }
    };
    else if (object == OBJECTS[1])
    {
         if (action == ACTIONS[0])
         {
           int classGrade;
           cout << "Please enter the grade of the class:" << endl;
           cin >> classGrade;
           if (classes[classGrade-1]!= NULL)
           {
             cout << "There is already a class in that age group." << endl;
           }
           else
           {
               classes[classGrade-1] = Class(classGrade);
           }
         }
         else if (action == ACTIONS[1])
         {
             int classNumber;
             cout << "Please enter a number of class." << endl;
             cin >> classNumber;
             int classAction;
             cout << "Please enter a number for the action you want." << endl;
             cout << "1. Get Grade.\n 2. Get Students" << endl;
             cin >> classAction;
             if (classAction == 1)
             {
                  cout << classes[classNumber-1].GetGrade() << endl;
             }
             else
             {
                 classes[classNumber-1].GetStudents();
             }
         }
         else
         {
             int studentNumInSchool;
             int classNumber;
             cout << "Please enter a number of class." << endl;
             cin >> classNumber;
             cout << "Please enter the number of student you want to add to the class." << endl;
             cin >> studentNumInSchool;
             classes[classNumber-1].AddStudent(students[studentNumInSchool]);
             
         }
    };
    else
    {
    };
    cout<<"Press Return to exit...";
    cin.sync();
    cin.ignore();
    
}
