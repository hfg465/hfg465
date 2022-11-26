#include<reg52.h>
sbit LED=P1^0;
sbit MOTOR=P3^0;
unsigned int i,j;
void main()
{
 MOTOR=0;
 while(1)
 {
  LED=0;//¡¡
  for(i=0;i<10;i++)
     for(j=0;j<10;j++);
  LED=1;//¡¡
  for(i=0;i<10;i++)
     for(j=0;j<10;j++);
 }
}