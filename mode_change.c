void mode_A()
{	
		unsigned char x=10;
	
		ADC0_start();
		ADC_wait();
		ADC0_conversion();
		
        ADC_close();
    
		ADC1_start();
		ADC_wait();
		ADC1_conversion();
		
        ADC_close();
    
		ADC6_start();
		ADC_wait();
		ADC6_conversion();
	
		ADC_close();
		
		while(x--)
		{		
				send_byte(ADC0_result,ADC1_result,ADC6_result);
		}
        RES();
        
}

void mode_B()
{
		get_unknow_num();
		show_unknow_num();
        
}

void mode_C()
{
	Aya_Gen();
    
}

