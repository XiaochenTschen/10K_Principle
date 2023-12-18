// test with shallow copy

#include <iostream>

class MyCopy
{
public:
    double *_myNumber;
    std::string _myName;

    MyCopy()
    {
        std::cout << "Constructor" << std::endl;
        _myNumber = new double{0.0};
    }

    ~MyCopy()
    {
        std::cout << "Destructor" << std::endl;
        delete _myNumber;
    }

    void printValueAndHandler()
    {
        std::cout << "obj name: " << _myName;
        std::cout << ", heap address = " << _myNumber;
        std::cout << ", value = " << (_myNumber!=nullptr? *_myNumber:0.0) << std::endl;
    }
};

int main()
{
    MyCopy s1;
    s1._myName = "s1";
    *s1._myNumber = 24.0;

    MyCopy s2;
    s2._myName = "s2";
    *s2._myNumber = 32.0;

    s1.printValueAndHandler();
    s2.printValueAndHandler();

    std::cout << "shallow copy happens: " << std::endl;
    // see how shallow copy works
    s2 = s1;
    s2.printValueAndHandler();

    std::cout << "change the member value after copy: " << std::endl;
    *s2._myNumber = 44.0;
    s2._myName = "afterShallowCopy";
    s1.printValueAndHandler(); // _myName is a steck member, so it is indvidual in each obj
    s2.printValueAndHandler(); //_myNumber is a heap member, so shallow copy make it to be schared between different objs

    return 0;
}