#include <iostream>
#include "include/student_db_cpp/class.h"
#include "include/student_db_cpp/course.h"
#include "src/common.cpp"
#include "src/studentFunctions.cpp"
using namespace std;

int main(int argc, char* argv[])
{
    string OBJECTS[] = {"STUDENT", "CLASS", "COURSE"};
    string ACTIONS[] = {"CREATE", "GET", "ADD"};
    if (argc != 3 || !in_array(argv[1], OBJECTS))
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
        createStudent(&students, &studentNumber);
      }
      else if (action == ACTIONS[1])
      {
          getStudent(&students);
      }
    }
    else if (object == OBJECTS[1])
    {
         if (action == ACTIONS[0])
         {
           int classGrade;
           cout << "Please enter the grade of the class:" << endl;
           cin >> classGrade;
           if (classGrade > 12 or classGrade < 1)
          {
            cout << "The class doesn't exist" << endl;
            goto end;
          }
           else if (classes[classGrade-1].GetGrade() != 0)
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
             if (sizeof(classes)/ sizeof(classes[0]) < classNumber)
             {
              cout << "The class doesn't exist" << endl;
              goto end;
             };
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
             if (sizeof(classes)/ sizeof(classes[0]) < classNumber)
             {
              cout << "The class doesn't exist" << endl;
              goto end;
             };
             cout << "Please enter the number of student you want to add to the class." << endl;
             cin >> studentNumInSchool;
             classes[classNumber-1].AddStudent(students[studentNumInSchool]);
             
         }
    }
    else
    {
        if(action == ACTIONS[0])
        {
          string courseName;
          cout << "Please enter the name of the new course" << endl;
          courses[courseNumber] = Course(courseName);
        }
        else if (action == ACTIONS[1])
        {
             int actionNumber;
             int courseNumber;
             cout << "Please enter the number of the course you want to GET:" << endl;
             cin >> courseNumber;
             if (sizeof(courses)/ sizeof(courses[0]) < courseNumber)
             {
              cout << "The course doesn't exist" << endl;
              goto end;
             };
             cout << "Please enter the number of the action you want to use:" << endl;
             cout << "1. Get Name\n2. Get Students." << endl;
             cin >> actionNumber;
             if (actionNumber == 1)
             {
               cout << courses[courseNumber].GetName() << endl;
             }
             else if (actionNumber == 2)
             {
                  courses[courseNumber].GetStudents();
             };
        }
        else
        {
             int studentNumInSchool;
             int courseNumber;
             cout << "Please enter a number of course." << endl;
             cin >> courseNumber;
             if (sizeof(courses)/ sizeof(courses[0]) < courseNumber)
             {
              cout << "The course doesn't exist" << endl;
              goto end;
             };
             cout << "Please enter the number of student you want to add to the course." << endl;
             cin >> studentNumInSchool;
             courses[courseNumber].AddStudent(students[studentNumInSchool]);
        }
    };
end:
    cout<<"Press Return to exit...";
    cin.sync();
    cin.ignore();
    
}
