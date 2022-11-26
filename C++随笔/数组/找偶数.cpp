#include<iostream>
using namespace std;
int main()
{
	int i,n,j,a[20],b[20];
	j=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		if(a[i]%2==0)
		{
			b[j]=a[i];j++;
		}
		for(i=0;i<j;i++)
			cout<<b[i]<<" ";
		cout<<endl;
}