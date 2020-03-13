#include<iostream>
using namespace std;
int main()
{
	int a[20],n,i,*p;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	p=&a[0];
	for(i=0;i<n;i++)
		cout<<*(p+i)*2<<" ";
	cout<<"\n";
}