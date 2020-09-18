// course.h
class Course
{
private:
    char[10] name;
    Student[] students;
public:
    Course(char[10] name);
    char[] GetName(){return name;};
    Student[] GetStudents(){return students;};
};
