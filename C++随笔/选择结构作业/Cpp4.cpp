/*��������������һ�ֶκ������£����д��������xֵ�����yֵ��
 
���������롿-1
�����������-1.4597
���������롿-0.5
�����������1.5874
���������롿1.57
�����������0.999999*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	float x,y;
	cin>>x;
	if(x<=-1)y=2*x+cos(x);
	else if(x<1)y=1.0/pow(x+1,2.0/3.0);
	else y=sin(x)*sin(x);
	cout<<y<<"\n";
}