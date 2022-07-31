#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int
void delay(uint x)
{
 uint i,j;
 for(i=x;i>0;i--)
   for(j=110;j>0;j--);
   }
void main()
{
 uchar m;
  m=0xfe;
 while(1)
 {
  P1=m;
  delay(500);
  m=_crol_(m,1);
  }
 }