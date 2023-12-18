#include<iostream>

int main()
{
    int i = 1;
    int& j = i;
    // int& k = 5; //ERROR: Lvalue reference can not connect with Rvalue
    std::cout << "addresse of source: " << &i << std::endl;
    std::cout << "addresse of reference: " << &j << std::endl; // same address as i

    j = 2;
    std::cout << "i: " << i << std::endl;
    return 0;
}