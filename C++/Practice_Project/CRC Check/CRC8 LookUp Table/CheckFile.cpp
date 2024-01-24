
#include<iostream>
#include<stdint.h>
#include<bitset>

using namespace std;

int main()
{
	int divident = 8;
	int sizeInt;
	uint8_t remainder;
	
	sizeInt = sizeof(divident);
	
	cout << sizeInt << endl;
	// cout << bitset<sizeInt*8>(divident) << endl; // error
	cout << bitset<sizeof(divident)*8>(divident) << endl;
	
	// remainder = (divident << (sizeInt - 1)*8);
	remainder = divident;
	cout << bitset<sizeof(remainder)*8>(remainder) << endl;
	
}
