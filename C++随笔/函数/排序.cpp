#include<iostream>
using namespace std;
int main()
{
	int a,n,b[50],i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>b[i];
	void pai(int [],int);
	pai(b,n);
	for(i=0;i<n;i++)
		cout<<b[i]<<" ";
	cout<<endl;
}
void pai(int a[],int n)
{
	int i,k,t;
	for(i=0;i<n-1;i++)
		for(k=i+1;k<n;k++)
			if(a[i]<a[k])
			{
				t=a[i];a[i]=a[k];a[k]=t;
			}
}