
#include<stdio.h>
#include<stdint.h> // include the defination of uint8_t
#include<iostream>

#define POLYNOMIAL 0xD8

using namespace std;

uint8_t crcNaive(uint8_t const message)
{
	uint8_t remainder;
	
	remainder = message; // initinally, the divident is the remainder.
	
	// for each bit position in divident	
	for (uint8_t bit = 8; bit > 0; --bit)
	{
		if (remainder & 0x80) // check if the uppermost bit is 1
		{
			remainder ^= POLYNOMIAL;
		}
		remainder = (remainder << 1);
	}
	return (remainder >> 4);
}

int main()
{
	uint8_t message = 0x86;
	uint8_t remainder = crcNaive(message);
	
	cout << "remainder is: " << cout << remainder << endl;
	
	int size;
	size = sizeof(remainder);
	cout << "size of remainder is:" << size << endl;
	
	return 0;
}
