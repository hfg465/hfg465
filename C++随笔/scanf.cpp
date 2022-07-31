#include<stdio.h>
int main()
{
	char t1,t2;
	int t3;
	float t4;
	scanf("%c,%c,%d,%f",&t1,&t2,&t3,&t4);
	printf("t1=%c,t2=%c,t3=%d,t4=%f\n",t1,t2,t3,t4);
	printf("t1=%d,t2=%d,t3=%c,t4=%d\n",t1,t2,t3,t4);
    printf("t1=%f,t2=%f,t3=%f,t4=%f\n",t1,t2,t3,t4);
}