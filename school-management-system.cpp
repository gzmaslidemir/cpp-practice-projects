#include <iostream>
using namespace std;

//Abstract base class
class Person {
protected:
    //protected attributes
    string Name; 
    int Age;

public: 
    Person(string name, int age) {
        Name = name;
        Age = age;
    }
    
    virtual string getRole() = 0;
    
    virtual void DisplayInfo() =0;

};
//Student Class
class Student: public Person {

private:
    int GradeLevel;
    
public:
    //Constructor
    Student(string name, int age, int gradeLevel)
    :Person(name, age) 
    {
        GradeLevel = gradeLevel;
    }
    
    //Setter 
    void setGradeLevel(int gradeLevel) {
        GradeLevel = gradeLevel;
    }
    //Getter
    int getGradeLevel() {
        return GradeLevel;
    }
    //Overridden getRole function
    string getRole() override {
        return "Student";
    }
    
    void Introduction() {
        cout << "Enter student details: " << Name << ", " << Age << ", Grade: " << GradeLevel << endl;
        } 
        
    void DisplayInfo() override {
            cout << Name << " is a " << getRole() << ", Age: " << Age << ", Grade Level: " << GradeLevel << endl;
    }    
 
};
//Teacher Class
class Teacher: public Person {
private:
    string Subject;
public:
    //Constructor
    Teacher(string name, int age, string subject)
    :Person (name, age)
    {
        Subject = subject; 
    }
    
    //Setter 
    void setSubject(string subject) {
        Subject = subject;
    }
    //Getter
    string getSubject() {
        return Subject;
    }
    //Overridden getRole function
    string getRole() override {
        return "Teacher";
    }
   
    void Introduction() {
        cout << "Enter teacher details: " << Name << ", " << Age << ", " << Subject << endl;
    }
    void DisplayInfo() override {
        cout << Name << " is a " << getRole() << ", Age: " << Age << ", Subject: " << Subject << endl;
    }
    
};

int main()
{
   //Creating Student and Teacher objects
   Student student1("John", 16, 10);
   student1.Introduction();
   
   Teacher teacher1("Mrs. Smith", 40, "Mathematics");
   teacher1.Introduction();
   
   cout << endl;
   cout << "School Members: " << endl;
   
   //Polymorphism using base class pointer
   Person* p;
   
   p = &student1;
   p->DisplayInfo();
   
   p = &teacher1;
   p->DisplayInfo();
   
   return 0;
}
