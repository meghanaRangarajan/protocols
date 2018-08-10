#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;
	uint64_t code = 0xC80412700;    
	wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;

while(1)
{
     uint32_t size = 36;
	uint64_t mask = 0x000000001;
int i;
int a;
int logic;
int m;
for(m=0;m<2,m++)
{
	digitalWrite(pin,1);
        usleep(2600);
        digitalWrite(pin,0);
        usleep(830);
        
	for(i = 0; i<size ;i++)//to detect the size of the code to be sent
	{
		a = (size-i-1);
		if(i != 3)
{
		if((mask & (code >>(size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,0);
        		usleep(380);
        		digitalWrite(pin,1);
        		usleep(380);
			
		}
		else// for logical 1
		{    
			digitalWrite(pin,1);
        		usleep(380);
        		digitalWrite(pin,0);
        		usleep(380);
		}
}
		
		else
{
		if((mask & (code >>(size-i-1))) == 0)//for logical 0
		{
			digitalWrite(pin,0);
        		usleep(830);
        		digitalWrite(pin,1);
        		usleep(830);
			
		}
		else// for logical 1
		{    
			digitalWrite(pin,1);
        		usleep(830);
        		digitalWrite(pin,0);
        		usleep(830);
		}
}
	}
digitalWrite(pin,0);
delay(7028);
}

}
}