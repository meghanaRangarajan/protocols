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
		uint32_t size = 48;
        digitalWrite(pin,1);
        usleep(3360);
        digitalWrite(pin,0);
        usleep(3360);

	uint64_t mask = 0x000000000001;
	int i;
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		if((mask & (code >> i)) == 0)//for logical 0
		{
			digitalWrite(pin,1);
			usleep(800);
			digitalWrite(pin,0);
			usleep(800);
		}
		else// for logical 1
		{       
			digitalWrite(pin,1);
			usleep(800);
			digitalWrite(pin,0);
			usleep(2500);
		}
	}
delay(89);
}