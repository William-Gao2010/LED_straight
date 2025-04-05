#ifndef __STC8G_H__
#define __STC8G_H__

void L();
void H();
void RES();
void send_byte(unsigned char R,unsigned char G,unsigned char B);

/*----------------------------*/
void ADC0_start();
void ADC0_close();
void ADC0_wait();
void ADC0_conversion();

/*---------------------------*/
void ADC1_start();
void ADC1_close();
void ADC1_wait();
void ADC1_conversion();


#endif