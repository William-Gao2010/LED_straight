#include <STC8G.H>
#include "intrins.H"
#include "straight.c"
#include "unknow_num.c"
#include "Aya_Gen.c"
#include "mode_change.c"

sbit KEY1 = P3^3;


void main()
{
	P1M0 = 0X00; P1M1 = 0X00;				
	P3M0 = 0X00; P3M1 = 0X00; 
	P5M0 = 0X00; P5M1 = 0X00;
    KEY1 = 1;
	while(1)
    {
        mode_A();
        if(KEY1==0)
         {
         Delay1ms(5);
         if(KEY1==0)
         {
          break;
         }
        }
    }
	
    while(1)
    {
        mode_B();
        if(KEY1==0)
         {
         Delay1ms(5);
         if(KEY1==0)
         {
          break;
         }
        }
    }
    
    while(1)
    {
        mode_C();
        if(KEY1==0)
         {
         Delay1ms(5);
         if(KEY1==0)
         {
          break;
         }
        }
    }
    
 }  