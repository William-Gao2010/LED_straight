#include <STC8G.H>

sbit OUT = P3^7;

unsigned char ADC0_result;
unsigned char ADC1_result;
unsigned char ADC6_result;

void Delay1ms(unsigned char num)	//@11.0592MHz
{
     while(num--)
	{	
	unsigned char data i, j;

	i = 15;
	j = 90;
	do
	{
		while (--j);
	} while (--i);
	}
}

void L()        //@35.000MHz         0.37US      8G1K17                1
    {
        unsigned char a=5,i=13;
        OUT=1;
        while (--a);
        OUT=0;
        while (--i);
        }
void H()        //@35.000MHz          0.81US
    {
        unsigned char a=16,i=3;
        OUT=1;
        while (--a);
        OUT=0;
        while (--i);
    }

void RES()   //35M         delay84us
{
    unsigned char a,b;
    OUT=0;
    for(b=50;b>0;b--)
    for(a=5;a>0;a--);
    
}

void send_byte(unsigned char R,unsigned char G,unsigned char B)
{
    unsigned char    i;
		for(i=0;i<8;i++)
		{
				if(G&0x80)
						H();
				else
						L();
				G=G<<1;                                
		}
		
		
		for(i=0;i<8;i++)
		{
				if(R&0x80)
						H();
				else
						L();
				R=R<<1;
		}
		
		
		for(i=0;i<8;i++)
		{
			 if(B&0x80)
						H();
			 else
						L();
				B=B<<1;
		}
	
}

void ADC0_start()                            
{    	
			ADC_CONTR  = 0x80 ;                                 //???
			ADCTIM   =  0x3f;																		//??????
			ADCCFG	=	0x00;
}

void ADC1_start()                            
{    	
			ADC_CONTR  = 0x81 ;                                 //???
			ADCTIM   =  0x3f;																		//??????
			ADCCFG	=	0x00;
}

void ADC6_start()                            
{    	
			ADC_CONTR  = 0x86 ;                                 //???
			ADCTIM   =  0x3f;																		//??????
			ADCCFG	=	0x00;
}



void ADC_wait()                            
{    	
		Delay1ms(1);
}
	
void ADC_close() 
{
		ADC_CONTR  =  0xE0;                                 //???1???
}

void ADC0_conversion()
{
	ADC0_result =(ADC_RESL << 8) | ADC_RES;
}

void ADC6_conversion()
{
	ADC6_result =(ADC_RESL << 8) | ADC_RES;
}

void ADC1_conversion()
{
	ADC1_result =(ADC_RESL << 8) | ADC_RES;
}
/*-------------------------------------------------------------*/

void all_OFF(unsigned char i)
{
	while(i--)
	{
	L();L();L();L();L();L();L();L();
	L();L();L();L();L();L();L();L();
	L();L();L();L();L();L();L();L();
	}
}