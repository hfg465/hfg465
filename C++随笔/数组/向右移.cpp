#include<iostream>
using namespace std;
int main()
{
	int n,i,t,a[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	t=a[n-1];
	for(i=n-1;i>0;i--)
		a[i]=a[i-1];
		a[0]=t;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}