#include<iostream>
using namespace std;

class basic
{public:
    basic(){};
    basic(int a):_a(a)
    {
        cout << "basic class " << _a << " constructed" << endl;
    }
    ~basic()
    {
        cout << "basic class " << _a << " deconstructed" << endl;
    }

    int getNum()
    {
        cout << "get num from basic class " << endl;
        return _a;
    }

private:
    int _a;
};

class driven:public basic
{
public:
    driven(int a, int b):basic(a), _b(b) /*learn to use*/
    {
        cout << "driven class " << _b << " constructed" << endl;
    }
    ~driven()
    {
        cout << "driven class " << _b << " deconstructed" << endl;
    }

    int getNum() /*overwrite*/
    {
        cout << "get num from driver class " << endl;
         return _b;
        /*return basic::getNum();*/
    }
    int getNumFromBasic()
    {
        cout << "get basic num from driven class" << endl;
        return basic::getNum();
    }

private:
    int _b;

};

/*
reference or non-reference parameter is different
non-reference param will make a copy, thus desconstruct func will be called after printNum
reference param will not call desconstruct
*/
void printNum(basic &obj)
{
    // which getNum() function will be called depends on the type of obj
    // here obj is basic type
    // thus either basic or driven type, getNum() from basic will always be called
    // but the data depends on the obj where it actually saved
    cout << "ptint function : " << obj.getNum() << endl;
}

int main()
{
    basic btest(1);
    driven test(2,3);
    cout << test.getNum() << endl;
    cout << "size of driven obj is " << sizeof(test) << endl;
    printNum(test);
    printNum(btest);

    basic* pBasic;
    pBasic = &test;
    pBasic->getNum();

    return 0;
}