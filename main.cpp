#include <iostream>
#include "include/student_db_cpp/class.h"
#include "include/student_db_cpp/course.h"
#include "src/common.cpp"
#include "src/studentFunctions.cpp"
#include "src/classFunctions.cpp"
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
           addClass(&classes);
         }
         else if (action == ACTIONS[1])
         {
             getClass(&classes);
         }
         else
         {
             addStudentToClass(&classes, &students);
             
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
