#include<iostream>
using namespace std;
int main()
{
	int a[20],i,n,*p;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	p=a;//p=a[0]
	cout<<*p<<" "<<*p+1<<endl;
	p++;
	cout<<*(p+2)<<endl;
}