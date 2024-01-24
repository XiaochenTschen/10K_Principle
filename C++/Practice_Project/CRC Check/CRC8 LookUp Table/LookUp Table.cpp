
/* 
 create the look up table for CRC8 byte weise
 save this look up table in a text file
*/

#include<iostream>
#include<stdint.h>
#include<fstream>

using namespace std;

int main()
{
	uint8_t crcTable[256];
	uint8_t remainder;
	uint8_t checkNum = 0xD8;
	
	cout << "Start to calculate ...." << endl;
	
	for(int divident = 0; divident < 256; ++divident) // divident from 0 to 255, calculate each remainder and save them in crcTable
	{
		remainder = divident;
		for (int i = 8; i > 0; --i) // calculate the remainder in bit weise
		{
			if (remainder & 0x80) // MSB check
			{
				remainder ^= checkNum;
			}
			else
			{
				remainder = (remainder << 1);
			}
		}
		crcTable[divident] = remainder;
		
	}
	
	cout << "Calculation finished !!!!" << endl;
	
	ofstream fout; 
	fout.open("crcTable.txt");
	
	for (int i = 0; i < 256; ++i)
	{
		if (i%8 == 0)
		{
			fout << "\n" << hex << (unsigned int)crcTable[i] << " ";
		}
		else
		{
			fout << hex << (unsigned int)crcTable[i]<< " ";
		}
	}
	
	fout << flush;
	fout.close();
	
	return 0;
}
