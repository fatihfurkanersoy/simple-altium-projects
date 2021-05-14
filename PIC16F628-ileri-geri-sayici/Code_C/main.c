// Örnek Program: Konya Teknik Üniversitesi, EEM Bölümü
#include <16F628A.h> //16F628A mikroiþlemcisi kullanýlýyor
#use delay(crystal=4000000) //kristal frekansý 4Mhz
//B portunun 8 pini LED1-2-3-4-5-6-7-8 ile tanýmlandý
#define LED1 PIN_B0
#define LED2 PIN_B1
#define LED3 PIN_B2
#define LED4 PIN_B3
#define LED5 PIN_B4
#define LED6 PIN_B5
#define LED7 PIN_B6
#define LED8 PIN_B7
#use fast_io(A)
#use fast_io(B)
#define buton PIN_A0
#define bekle 500
int say=0;
void main()
{
set_tris_A(0b00000001);
set_tris_B(0x00);
output_B(say); //program baþlatýldýðýnda tüm ledler sönük
while(1)
{
if (input(buton)) {say=say+1; output_B(say);}
else {say=say-1; output_B(say);}
delay_ms(bekle);
}
}
