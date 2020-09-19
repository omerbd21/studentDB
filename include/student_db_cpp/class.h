// class.h
using namespace std;
#include "student.h"
class Class
{
private:
    int classGrade;
    int studentNumber;
    Student students[40];
public:
    Class(int Grade)
    {
       classGrade=Grade;
       studentNumber = 0;
    };
    Class (){
          classGrade = 0;};
    int GetGrade()
    {
       return classGrade; 
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
         if (student.GetGrade() != classGrade)
         {
             cout << "This is not his grade" << endl;
         }
         else
         {
             students[studentNumber] = student;
             studentNumber++;
         }
    };
};
