/*��������������д�������ĳ��ĳ�µ��������������year���·�month,������·ݵ������� 
��������ʽ���������֣��м��ÿո����
�������ʽ��һ������
���������롿2012 2
�����������29
������˵����2012��2����29��*/
#include<iostream>
using namespace std;
int main()
{
	int year,month,days;
	cin>>year>>month;
	if(year%4==0&&month==2)
		days=29;
	if(year%4!=0&&month==2)
		days=28;
	if(month!=2)	
	{
		if(month<=7)
		{
			if(month%2==0)days=30;
			else days=31;
		}
		else
		{
			if(month%2==0)days=31;
			else days=30;
		}
	}
		cout<<days<<"\n";
}
