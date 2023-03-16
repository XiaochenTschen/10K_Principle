#include<iostream>
#define EEPROM_EMULATION_SIZE 8192

using namespace std;

main()
{
    typedef struct
    {
        char data[EEPROM_EMULATION_SIZE];
        bool valid;
    } EEPROM_EMULATION;

    __attribute__((__aligned__(8192)))
    static const char testObj[(sizeof(EEPROM_EMULATION)+8191)/8192*8192] = { };

    cout << "size of testObj is " << sizeof(testObj) << endl;

    return 0;

}