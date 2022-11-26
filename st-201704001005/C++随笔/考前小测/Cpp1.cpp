#include<stdio.h>
void main( )
{  int  a=-2, b=2;
   for(; ++a && --b;)
         ;
   printf("%d,%d\n", a,b);
}
