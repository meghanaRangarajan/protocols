#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;
	uint32_t size = 12;
	wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;

while(1)
{
	uint32_t size = 32;
	uint64_t code1 = codex;
	uint64_t mask = 0x00000001;
	int i;

    digitalWrite(pin,1);
    usleep(4500);
    digitalWrite(pin,0);
    usleep(4500);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code1 >> (size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(500);
			digitalWrite(pin,0);
			usleep(500);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(500);
			digitalWrite(pin,0);
			usleep(1620);
		}
	}	
delay(89);
}
}