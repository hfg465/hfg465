#include<iostream>
using namespace std;
int main()
{
	int a[50],n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	float cios(int [],int);
	cout<<cios(a,n)<<","<<cios(a,n)/n<<"\n";
}
float cios(int a[],int n)
{
	float p=0;
	int i;
	for(i=0;i<n;i++)
		p+=a[i];
	return p;
}