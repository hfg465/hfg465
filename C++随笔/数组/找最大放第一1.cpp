#include <iostream>
using namespace std;
int main( )
{
	int t[50],i,n,p;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>t[i];
	for(i=1;i<n;i++)
		if(t[i]>t[0])
		{
		    p=t[0];t[0]=t[i];t[i]=p;
		}
	for(i=0;i<n;i++)
		cout<<t[i]<<" ";
}
