#include <iostream>
#include <string>
using namespace std;

/*
 * a friend class has full access of this class members
 * friendship is one direction
 * friendship can not be passed
 * A is friend of B, B is friend of C, not means A is friend of C
 */

/*
 * Address class forward declaration
 */
class Address;

class Student{
public:
    Student(string name, int age, float score);
public:
    void show(Address *addr);  //declar show() as friend function
private:
    string m_name;
    int m_age;
    float m_score;
};

class Address{
private:
    string _province;
    string _city;
    string _district;
public:
    Address(string province, string city, string district);
    // this means Student class can access members of Address
    friend class Student;
};

/*
 * Define of function must after class Address 
 */
Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score){ }
void Student::show(Address *addr){
    cout << m_name << " age is " << m_age << ", score is " << m_score << endl;
    cout << "Address is: " << addr->_province << ", " << addr->_city << ", " << addr->_district << endl;
}

Address::Address(string province, string city, string district):_province(province),_city(city),_district(district){};


int main(){
    Student stu("Ming", 16, 90);
    Address addr("Shandong", "Weifang", "Qingzhou");
    stu.show(&addr);

    Student *pstu = new Student("Lei", 16, 95);
    Address *paddr = new Address("Shandong","Weifang","Linqu");
    pstu->show(paddr);

    return 0;
}