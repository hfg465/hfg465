/*��������������һ�ֶκ������£����д��������xֵ�����yֵ��
 
���������롿-2.5
�����������7.36396
���������롿1
�����������2
���������롿11
�����������0.222681*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float x,y;
	cin>>x;
	if(x<=-1)y=3*sqrt(fabs(x)+2)+1;
	else if(x<=10)y=pow(x,5)+1;
	else y=sqrt((x+1)/(2*x*x));
	cout<<y<<"\n";
}