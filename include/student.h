// student.h
class Student
{
private:
    int id;
    char[15] name;
    int grade;
public:
    Student(int id, char[15] name, int grade);
    int GetId(){return id;};
    char GetName(){return name;};
    int GetGrade(){return grade;};
    void GradeUp();
};
