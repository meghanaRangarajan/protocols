#include <unistd.h>
#include<iostream>
#include<wiringPi.h>
#include<math.h>

int main()
{
	int pin = 0;
	wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;

while(1)
{
	uint32_t size = 64;																						                                                       		
	uint64_t mask = 0x000000000000000f; 
	uint64_t code = 0x166f442a13063300;                                                         
	uint32_t slices = size / 4;                                                       
	int i;                                                       
	for(i = 0; i < slices; ++i)                                                       
	{                                                       
		if(i % 8 == 0 && i != 0)                                                       
		{                                                       
		digitalWrite(pin,1);
        usleep(210);
        digitalWrite(pin,0);
        usleep(13157);                                                       
		}                                                       
                                                       
		uint64_t dataSlice = (code >> ((slices - i - 1) * 4));                                                       
		dataSlice &= mask; 

		                                                       
		uint16_t space = ((dataSlice * 136)  + 763);                                                       
		digitalWrite(pin,1);
        usleep(210);
        digitalWrite(pin,0);
        usleep(space);                                                       
	}                                                       
	digitalWrite(pin,1);
    usleep(210);  
	digitalWrite(pin,0);
	delay(100);


                                                       
}
}