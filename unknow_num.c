#include "stdlib.h"

unsigned int unknow_LED,unknow_colorR,unknow_colorG,unknow_colorB;

void get_unknow_num()    
{
    unknow_LED = rand()%9;
    unknow_colorR = rand()%256;  
    unknow_colorG = rand()%256;
    unknow_colorB = rand()%256;
}

void show_unknow_num()
{
    all_OFF(unknow_LED);
    send_byte(unknow_colorR,unknow_colorG,unknow_colorB);
    all_OFF(9-unknow_LED);
    RES();
    Delay1ms(1000);
}