#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char
sbit suo1=P2^6;
sbit suo2=P2^7;
void delay(uint x)
{
 uint i,j;
 for(i=x;i>0;i--)
   for(j=110;j>0;j--);
   }
void main()
{
 uchar m=0xfe;
 suo2=1;
 P0=0x7f;
 suo2=0;
 suo1=1;
 P0=0xff;
 suo1=0;
 while(1)
 {
  P1=m;
  delay(500);
  m=_crol_(m,1);
  }
 }