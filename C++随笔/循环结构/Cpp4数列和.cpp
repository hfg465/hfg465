/*��������������һ�������� ����������е�ǰn��ͣ�n�ɼ������롣
���������롿20
�����������32.6603
������˵����������ǰ20��֮��Ϊ32.6603*/
#include<iostream>
using namespace std;
int main()
{
	int a,b,c,i,n;
	float s=0;
	cin>>n;
	a=1;b=2;
	for(i=1;i<=n;i++)
	{
		s+=1.0*b/a;
		c=b;
		b=a+b;
		a=c;
	}
	cout<<s<<endl;
}