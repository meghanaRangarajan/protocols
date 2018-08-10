//rcmm

#include <unistd.h>
#include<iostream>
#include<wiringPi.h>

int main()
{
	int pin = 0;
	uint32_t size = 16;
	wiringPiSetup () ;
    pinMode (pin, OUTPUT) ;

while(1)
{

        digitalWrite(pin,1);
        usleep(417);
        digitalWrite(pin,0);
        usleep(278);
 
        
	uint64_t code = 0xA608;
	uint64_t mask = 0x0003;
	int i;
	uint32_t slices = size / 2;
	int i;
	for(i = 0; i < slices; i++)//tge size of the for loop is only half the code size because we take two bits at a time
	{
		uint64_t dataSlice = (code >> ((slices - i - 1) * 2));//to get two bits 
		dataSlice &= mask; //to mask every other bits other than the ones we need

		switch(dataSlice)//four differrent cases for four diffeerent modes
		{
		case 0://00 : extended mode
		digitalWrite(pin,1);
        usleep(167);
        digitalWrite(pin,0);
        usleep(278);
		break;

		case 1://01 : mouse mode
		digitalWrite(pin,1);
        usleep(167);
        digitalWrite(pin,0);
        usleep(445); 
		break;

		case 2:// 10 : keyboard mode 
		digitalWrite(pin,1);
        usleep(167);
        digitalWrite(pin,0);
        usleep(611);
 		break;

		case 3:// 11 : game pad mode
		digitalWrite(pin,1);
        usleep(167);
        digitalWrite(pin,0);
        usleep(777);
		break;
		}
	}
delay(89);
}
}