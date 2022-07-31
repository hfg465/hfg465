#include<iostream>
using namespace std;
int main()
{
	int n,i,k,w,t,a[50];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n-1;i++)
	{
		w=i;
		for(k=i+1;k<n;k++)
			if(a[w]<a[k])
			{
				t=a[w];a[w]=a[k];a[k]=t;
			}
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}