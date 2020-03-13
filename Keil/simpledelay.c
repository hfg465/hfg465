#include<reg52.h>
#define uint unsigned int
uint i,j;
sbit m=P1^0;
void deley(uint x)
{
 for(i=x;i>0;i--)
   for(j=110;j>0;j--);
   }
void main()
{
  while(1)
  {
  m=0;
  deley(300);
  m=1;
  deley(700);
   }
   }