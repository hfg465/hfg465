#include<iostream>
using namespace std;
int main()
{
	int n,i,k,t,a[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
		for(k=i+1;k<n;k++)
			if(a[k]>a[i])
			{
				t=a[i];a[i]=a[k];a[k]=t;
			}
			for(i=0;i<n;i++)
				cout<<a[i]<<" ";
			cout<<endl;
}