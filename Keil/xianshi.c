#include<reg51.h>
#define uint unsigned int
#define uchar unsigned char
uint i,j;
sbit d1=P1^0;
sbit d2=P1^1;
sbit d3=P1^2;
sbit d4=P1^3;
sbit d5=P1^4;
sbit d6=P1^5;
sbit d7=P1^6;
sbit d8=P1^7;
void main()
{
 uchar table[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
 void delay();
 uchar a;
 uint k,m;
 while(1)
 {
  d1=d2=d3=d4=d5=d6=d7=d8=0;
  delay();
  d1=d2=d3=d4=d5=d6=d7=d8=1;
  delay();
  for(a=0;a<10;a++)
   {
     P0=table[a];
	 for(m=0;m<350;m++)
	   for(k=0;k<m;k++) ;
	 }
   }
}
void delay()
{
 for(i=0;i<10;i++)
    for(j=0;j<10;j++);
}