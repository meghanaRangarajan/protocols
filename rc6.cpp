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
       uint32_t size = 24;
    uint64_t mask = 0x000001;
     uint64_t code = 0xC00010;
    int i;
digitalWrite(pin,1);
        usleep(2600);
        digitalWrite(pin,0);
        usleep(830);

    for(i = 0; i<size ;i++)//to detect the size of the code to be sent
    {
        int a;
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
delay(100);
}
}