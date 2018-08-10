
#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;
	wiringPiSetup () ;
	pinMode (pin, OUTPUT) ;

while(1)
{    uint32_t size = 12;
	uint64_t code = 0x490;
	uint64_t mask = 0x001;
	int i;

    digitalWrite(pin,1);
    usleep(2400);
    digitalWrite(pin,0);
    usleep(550);
	
   
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code >> (size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(550);
			digitalWrite(pin,0);
			usleep(550);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(1150);
			digitalWrite(pin,0);
			usleep(550);
		}
	}
delay(27);
}
}


