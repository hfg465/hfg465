#include<iostream>
using namespace std;
void fun(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		 a[i]*=2;
}
int main()
{
	int a[50],i,n;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	fun(a,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}