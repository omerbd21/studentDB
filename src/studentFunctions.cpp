#include <string>
#include "../include/student_db_cpp/student.h"
using namespace std;
void createStudent(Student** students, int* studentNumber)
{
     int studentId;
     string studentName;
     int studentClass;
     cout << "Please enter an ID, a name and a class:" << endl;
     cin >> studentId;
     getline(cin, studentName);
     cin >> studentClass;
     *students[*studentNumber] = Student(studentId, studentName, studentClass);
     *(studentNumber)++;
}

void getStudent(Student** students)
{
      int studentNum;
      int getAction;
      cout << "Please enter the number of the student:" << endl;
      cin >> studentNum;
      if (sizeof(*(students))/ sizeof(students[0]) < studentNum)
      {
        cout << "The student doesn't exist" << endl;
        return;
      };
      cout << "Please enter the number for the GET action you want." << endl;
      cout << "1. Get ID\n2. Get Name\n3. Get Grade." << endl;
      cin >> getAction;
      if (getAction == 1)
      {
        Student s = *students[studentNum];
        cout << s.GetId() << endl;
      }
      else if (getAction == 2)
      {
           Student s = *students[studentNum];
           s.GetName();
      }
      else
      {
          Student s = *students[studentNum];
          cout << s.GetGrade() << endl;
      };
}
