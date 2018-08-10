
#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;
	wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;

while(1)
{
		uint32_t size = 12;
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
 
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
	uint64_t code = 0x73d;
	uint64_t mask = 0x001;
	int i;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code >> i)) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(830);
			digitalWrite(pin,0);
			usleep(830);
		}
		else// for logical 1
		{       
			digitalWrite(pin,0);
			usleep(830);
			digitalWrite(pin,1);
			usleep(830);
		}
	}
delay(89);
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
 
        digitalWrite(pin,0);
        usleep(830);
        digitalWrite(pin,1);
        usleep(830);
	uint64_t code = 0x73d;
	uint64_t mask = 0x001;
	int i;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code >> i)) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(830);
			digitalWrite(pin,0);
			usleep(830);
		}
		else// for logical 1
		{       
			digitalWrite(pin,0);
			usleep(830);
			digitalWrite(pin,1);
			usleep(830);
		}
	}
delay(89);
}
}


