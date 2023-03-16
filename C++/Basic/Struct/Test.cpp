#include<iostream>
using namespace std;

typedef struct{
    int a;
    long b;
    bool c;
    string s;
}testS;

int main()
{
    testS test1 = {1, 2, 0, "test"};
    testS *ptest = &test1;
    cout << sizeof(test1) << endl;
    cout << (*ptest).a << endl;
    cout << ptest->s << endl;
    return 0;
}