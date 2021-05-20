#include<p18f452.h>
#include<delays.h>
#include<xlcd.h>
#define CURSOR_OFF  0b00001101
void DelayFor18TCY(void)
{ 
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
Nop();
return;
}
void DelayPORXLCD(void)
{
	Delay1KTCYx(15);
	return;
}
void DelayXLCD(void)
{
	Delay1KTCYx(5);
	return;
}
unsigned int uni,dec,cen;
unsigned char Display[10]={'0','1','2','3','4','5','6','7','8','9'};
void main (void)
{
	ADCON1=0x07;
	TRISA=0xFF;
	OpenXLCD(FOUR_BIT & LINES_5X7);
	WriteCmdXLCD(SHIFT_DISP_LEFT);
	WriteCmdXLCD(BLINK_OFF);
	WriteCmdXLCD(0x80);
	putrsXLCD("CONTADOR 0 a 666");
	if(PORTAbits.RA1==0 && PORTAbits.RA2==0)
	{
		while(1)
		{
			cen=0;
			dec=0;
			uni=0;
			while(cen<10)
			{
				while(dec<10)
				{
					while(uni<10)
					{
						if(PORTAbits.RA1==0 && PORTAbits.RA2==0)
						{
							WriteCmdXLCD(0xcf);
							WriteDataXLCD(Display[uni]);
							WriteCmdXLCD(0xce);
							WriteDataXLCD(Display[dec]);
							WriteCmdXLCD(0xcd);
							WriteDataXLCD(Display[cen]);
							Delay10KTCYx(100);
							uni=uni+3;
							if(PORTAbits.RA0==1)
							{
								cen=0;
								dec=0;
								uni=0;
							}
						}
						else
						{
							return 0;
						}
					}
				uni=uni-10;
				dec++;
				}
			dec=dec-10;
			cen++;
		    }
		}
	}
	else if(PORTAbits.RA1==1 && PORTAbits.RA2==0)
	{
		while(1)
		{
			cen=9;
			dec=9;
			uni=8;
			while(cen>=0)
			{
				while(dec>=0)
				{
					while(uni>=0)
					{
						if(PORTAbits.RA1==1 && PORTAbits.RA2==0)
						{
							WriteCmdXLCD(0xcf);
							WriteDataXLCD(Display[uni]);
							WriteCmdXLCD(0xce);
							WriteDataXLCD(Display[dec]);
							WriteCmdXLCD(0xcd);
							WriteDataXLCD(Display[cen]);
							Delay10KTCYx(100);
							uni=uni-2;
							if(PORTAbits.RA0==1)
							{
								cen=9;
								dec=9;
								uni=8;
							}
						}
						else
						{
							return 0;
						}
					}
					uni=uni+10;
				dec--;
				}
			cen--;
		    }
		}
	}
	else if(PORTAbits.RA1==0 && PORTAbits.RA2==1)
	{
		while(1)
		{
			cen=0;
			dec=0;
			uni=0;
			while(cen<10)
			{
				while(dec<10)
				{
					while(uni<10)
					{
						if(PORTAbits.RA1==0 && PORTAbits.RA2==1)
						{
							WriteCmdXLCD(0xcf);
							WriteDataXLCD(Display[uni]);
							WriteCmdXLCD(0xce);
							WriteDataXLCD(Display[dec]);
							WriteCmdXLCD(0xcd);
							WriteDataXLCD(Display[cen]);
							Delay10KTCYx(100);
							uni=uni+4;
							if(PORTAbits.RA0==1)
							{
								cen=0;
								dec=0;
								uni=0;
							}
						}
						else
						{
							return 0;
						}
					}
				uni=uni-10;
				dec++;
				}
			dec=dec-10;
			cen++;
		    }
		}
	}
	else if(PORTAbits.RA1==1 && PORTAbits.RA2==1)
	{
		while(1)
		{
			cen=9;
			dec=9;
			uni=0;
			while(cen>=0)
			{
				while(dec>=0)
				{
					while(uni>=0)
					{
						if(PORTAbits.RA1==1 && PORTAbits.RA2==1)
						{
							WriteCmdXLCD(0xcf);
							WriteDataXLCD(Display[uni]);
							WriteCmdXLCD(0xce);
							WriteDataXLCD(Display[dec]);
							WriteCmdXLCD(0xcd);
							WriteDataXLCD(Display[cen]);
							Delay10KTCYx(100);
							dec--;
							if(PORTAbits.RA0==1)
							{
								cen=9;
								dec=9;
								uni=0;
							}
						}
						else
						{
							return 0;
						}
					}
				dec=dec+10;
				}
			cen--;
		    }
		}
	}
}
