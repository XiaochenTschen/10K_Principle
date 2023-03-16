#include <iostream>
#include <string>
using namespace std;

class Student{
public:
    Student(string name, int age, float score);
public:
    friend void show(Student *pstu);  //declar show() as friend function
private:
    string m_name;
    int m_age;
    float m_score;
};

Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score){ }

/*
 * As friend function, it can direct use private members of obj
 * Can not use private members from class
 */
void show(Student *pstu){
    cout<<pstu->m_name<<"age is "<<pstu->m_age<<", score is "<<pstu->m_score<<endl;
}


int main(){
    Student stu("Ming", 15, 90.6);
    show(&stu); 
    Student *pstu = new Student("Lei", 16, 80.5);
    show(pstu);  
    return 0;
}