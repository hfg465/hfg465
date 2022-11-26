#include<iostream>
using namespace std;
int main()
{
	int n,i,t,a[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	t=a[0];
	for(i=1;i<n;i++)
		a[i-1]=a[i];
		a[n-1]=t;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}