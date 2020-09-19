#include <string>
#include "../include/student_db_cpp/course.h"
using namespace std;
void createCourse(Course** courses, int* courseNumber)
{
     string courseName;
     cout << "Please enter the name of the new course" << endl;
     (*courses)[*courseNumber] = Course(courseName);
};
void getCourse(Course** courses)
{
     int actionNumber;
     int courseNumber;
     cout << "Please enter the number of the course you want to GET:" << endl;
     cin >> courseNumber;
     if (sizeof(courses)/ sizeof(courses[0]) < courseNumber)
     {
      cout << "The course doesn't exist" << endl;
      return;
     };
     cout << "Please enter the number of the action you want to use:" << endl;
     cout << "1. Get Name\n2. Get Students." << endl;
     cin >> actionNumber;
     if (actionNumber == 1)
     {
       cout << (*courses)[courseNumber].GetName() << endl;
     }
     else if (actionNumber == 2)
     {
          (*courses)[courseNumber].GetStudents();
     };
};
void addStudentToCourse(Course** courses, Student** students)
{
     int studentNumInSchool;
     int courseNumber;
     cout << "Please enter a number of course." << endl;
     cin >> courseNumber;
     if (sizeof(courses)/ sizeof(courses[0]) < courseNumber)
     {
      cout << "The course doesn't exist" << endl;
      return;
     };
     cout << "Please enter the number of student you want to add to the course." << endl;
     cin >> studentNumInSchool;
     (*courses)[courseNumber].AddStudent((*students)[studentNumInSchool]);
};
