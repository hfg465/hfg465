#include<iostream>
using namespace std;
int main()
{
	int n,i,k,x,a[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>x;
	for(i=0;i<n;i++)
		if(x>a[i])break;
			for(k=n;k>i;k--)
				a[k]=a[k-1];
			a[i]=x;
			for(i=0;i<n+1;i++)
				cout<<a[i]<<" ";
			cout<<endl;
}