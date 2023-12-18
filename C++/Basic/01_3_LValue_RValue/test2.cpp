#include <iostream>

void passValue(int &&param)
{
    std::cout << "Rvalue\n";
}

void passValue(int &param)
{
    std::cout << "Lvalue\n";
}

int main()
{
    int i{15};
    int &l_r = i;
    int &&r_r = 10;

    r_r = 20;
    std::cout << "r_r: " << r_r << std::endl;

    passValue(i);
    passValue(l_r);
    passValue(5);
    passValue(r_r);

    return 0;
}