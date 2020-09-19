#include <iostream>
#include "include/student_db_cpp/course.h"
#include "src/common.cpp"
#include "src/studentFunctions.cpp"
#include "src/classFunctions.cpp"
#include "src/courseFunctions.cpp"
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
           addClass(classes);
         }
         else if (action == ACTIONS[1])
         {
             getClass(classes);
         }
         else
         {
             addStudentToClass(classes, &students);
             
         }
    }
    else
    {
        if(action == ACTIONS[0])
        {
          createCourse(&courses, &courseNumber);
        }
        else if (action == ACTIONS[1])
        {
             getCourse(&courses);
        }
        else
        {
             addStudentToCourse(&courses, &students);
        }
    };
end:
    cout<<"Press Return to exit...";
    cin.sync();
    cin.ignore();
    
}
