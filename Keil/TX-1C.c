#include<reg51.h>
#define uint unsigned int
void delay(uint xms)
{
 uint i,j;
 for(i=xms;i>0;i--)
    for(j=110;j>0;j--);
}
void main()
{
 while(1)
 {
  P0=0x00;
  delay(1000);
  P0=0xff;
  delay(500);
  P0=0xaa;
  delay(1000);
  P0=0x55;
  delay(500);
 }
}