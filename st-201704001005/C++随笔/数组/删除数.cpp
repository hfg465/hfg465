//�ƶ����ݵ�ԭ��ɾ��������ĳ����
#include<iostream>
using namespace std;
int main()
{
	int n,i,t,p,x,a[50];
	cout<<"���������ݸ���:";
	cin>>n;
	cout<<"������һ���������:";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"������Ҫɾ��������";
	cin>>x;
	for(i=0;i<n;i++)
		if(x==a[i])
		{
			for(t=i+1;t<n;t++)
				a[t-1]=a[t];
			n--;i--;
		}
		for(i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
}