#include<iostream>
using namespace std;

class basic
{public:
    basic(){};
    basic(int a):_a(a)
    {
        cout << "basic class " << _a << " constructed" << endl;
    }
    // Deconstructur is usally defined as virtual
    virtual ~basic()
    {
        cout << "basic class " << _a << " deconstructed" << endl;
    }

    virtual int getNum()
    {
        return _a;
    }

private:
    int _a;
};

class driven:public basic
{
public:
    driven(int a, int b):basic(a) /*learn to use*/
    {
        _b = b;
        cout << "driven class " << _b << " constructed" << endl;
    }
    ~driven()
    {
        cout << "driven class " << _b << " deconstructed" << endl;
    }

    int getNum() /*overload*/
    {
         return _b;
        /*return basic::getNum();*/
    }

private:
    int _b;

};

/*
reference or non-reference parameter is different
non-reference param will make a copy, thus desconstruct func will be called after printNum
reference param will not call desconstruct
*/
void printNum(basic *obj)
{
    cout << "ptint function : " << obj->getNum() << endl;
}

int main()
{
    basic* btest;
    btest = new driven(2,3);
    // if getNum is not virtual, btest->getNum call the method in baisc class
    // if getNum is virtuall, btest->getNum call the method in driven class
    cout << btest->getNum() << endl;
    cout << "size of driven obj is " << sizeof(btest) << endl;
    printNum(btest);

    // if deconstructor in basic class is not virtual, delect btest only call dectr in basic
    // if deconstructor is virtual, delect btest call first dectr in basic and then dectr in driven
    delete btest;

    return 0;
}