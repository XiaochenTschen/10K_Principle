#include<iostream>

using namespace std;
typedef union
{
    struct{
        uint8_t part1:1;
        uint8_t part2:1;
        uint8_t part3:6;
    }bitPart;
    uint8_t wholePart;
}testUnion;


int main()
{
    testUnion test;
    test.wholePart = 170;
    cout << unsigned(test.bitPart.part1) << endl;
    cout << unsigned(test.bitPart.part2) << endl;
    cout << unsigned(test.bitPart.part3) << endl;

    return 0;
}