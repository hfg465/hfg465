#include<iostream>
using namespace std;
int jou(int a)
{
	if(a%2==1)
		return 1;
	else return 0;
}
int main()
{
	int a[50],n,i,js,os;
	js=os=0;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(jou(a[i])==1)js++;
		else os++;
	}
	cout<<js<<","<<os<<endl;
}