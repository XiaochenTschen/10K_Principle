
/* 
  check the MSB 
  how to output a number in binary and hex form
*/

#include<iostream>
#include<stdint.h>
#include<bitset>

using namespace std;

int main()
{
	uint8_t checkNum = 0x80; // unit8_t is unsigned char, the output directly is in character form, in number form should use form transformation
	cout << "the checkNum in binary form is: " << bitset<8> (checkNum) << endl;
	uint8_t message = 0xD8;
	cout << "the message in binary form is: " << bitset<8> (message ) << endl;	
	
	int result;
	int size;
	
	result = (message & checkNum); // MSSB check
	size = sizeof(checkNum); // result of sizeof() is in byte size
	
	//cout << "the message is " << hex << (unsigned int) message << endl;
	//cout << "the result is: "  << result << endl;
	cout << "the result in binary form is: " << bitset<8> (result)<< endl;
	cout << "the size of message is: " << size << endl;
	
	return 0;
	
 } 
