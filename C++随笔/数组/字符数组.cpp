/*����5��Сд��ĸ��������ԭ������ĸ�����4����ĸ���档���磬��ĸ��a����ɡ�e�� ����ĸ
��x����ɡ�b����*/
#include<iostream>
using namespace std;
int main()
{
	char a[20],i;
	cin>>a;
	for(i=0;a[i]!=0;i++)
	{
		a[i]+=4;
		if(a[i]>'z')
			a[i]-=26;
	}
	cout<<a<<endl;
}
