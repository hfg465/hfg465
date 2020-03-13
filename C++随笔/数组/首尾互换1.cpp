#include<iostream>
using namespace std;
int main()
{
	int n,i,b,t,e,a[50];
	cin>>n;
	b=0;e=n-1;
	for(i=0;i<n;i++)
		cin>>a[i];
	while(b<e)
	{
		t=a[b];a[b]=a[e];a[e]=t;
		b++;e--;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}