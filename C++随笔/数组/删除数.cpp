//移动数据的原理删除数组中某个数
#include<iostream>
using namespace std;
int main()
{
	int n,i,t,p,x,a[50];
	cout<<"请输入数据个数:";
	cin>>n;
	cout<<"请输入一组随机数据:";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<"请输入要删除的数：";
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