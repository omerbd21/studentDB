#include <iostream>
#include "include/student_db_cpp/class.h"
#include "include/student_db_cpp/course.h"
#include "src/common.cpp"
using namespace std;

int main()
{
    string OBJECTS[] = {"student", "class", "course"};
    string ACTIONS[] = {"CREATE", "GET"};
    if (argc != 3 || in_array(argv[1], OBJECTS))
     {
          std::cerr << "Usage: main [Object] [Action]"
                              << std::endl;
          return 0;
     }
    
    char* object = argv[1];
    char* action = argv[2];
    Student* students;
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
      else
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
    cout<<"Press Return to exit...";
    cin.sync();
    cin.ignore();
    
}
