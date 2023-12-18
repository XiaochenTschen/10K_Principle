#include <iostream>

class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor" << std::endl;
    }
    ~MyClass()
    {
        std::cout << "Destructor" << std::endl;
    }
    MyClass(const MyClass &source)
    {
        std::cout << "Copy Constructor" << std::endl;
    }
    MyClass& operator=(const MyClass &source)
    {
        std::cout << "Copy Assignment" << std::endl;
        return *this;
    }
};

int main()
{
    MyClass m1; // Constructor
    MyClass m2 = m1; // Copy Contructor not assignment, because it is the same as copy constructor
    MyClass m3(m1); // Copy Constructor
    MyClass m4; // Constructor
    m4 = m1; // Copy Assignment
    return 0;
}