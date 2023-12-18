#include<iostream>

using namespace std;

int add(int a, int b)
{
    return a+b;
}

int add1(int (*fp)(int, int), int a, int b, int c)
{
    return fp(a,b)+c;
}

int main()
{
    /* declaration and initialization of function pointer */
    /*
     int (*callback)(int,int) = &add;
     cout << add1(callback, 1, 2, 3) << endl;
    */

    /*Function name is the pointer of this function*/
    cout << add1(add, 1, 2, 3) << endl;

    return 0;
}