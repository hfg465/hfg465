#include <iostream>
using namespace std;
int main( )
{
	int a[50],x,n,i;
	cin>>x;
	n=0;
	while(x>0)
	{    
		a[n]=x;
		n++;
		cin>>x;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}
