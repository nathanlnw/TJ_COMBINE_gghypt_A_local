#include  <string.h>
#include "Menu_Include.h"


static void msg( void *p)
{

}
static void show(void)
{
        //MenuIdle_working=0;//clear  
		lcd_fill(0);
		lcd_text12(20, 10,"SIM¿¨Ç··Ñ",9, LCD_MODE_SET); 
		lcd_update_all();
}


static void keypress(unsigned int key)
{
	switch(KeyValue)
		{
		case KeyValueMenu:		
		case KeyValueOk: 
		case KeyValueUP:
		case KeyValueDown:			   
			   pMenuItem=&Menu_1_Idle;
			   pMenuItem->show();
			   break;
		}
	KeyValue=0;
}


static void timetick(unsigned int systick)
{
	CounterBack++;
		if(CounterBack!=MaxBankIdleTime)
			return;
		pMenuItem=&Menu_1_Idle;
		pMenuItem->show();
		CounterBack=0;

}


MENUITEM	Menu_8_SIMnoFee=
{
    "¿¨Ç··Ñ",
	6,
	&show,
	&keypress,
	&timetick,
	&msg,
	(void*)0
};



