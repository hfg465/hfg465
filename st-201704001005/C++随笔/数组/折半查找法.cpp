/*#include <iostream>
using namespace std;
int main( )
{	int a[50],x,i,n,t,b,m,f;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>x;
	t=0;b=n-1;f=0;
	while(t<=b)
	{	m=(t+b)/2;
		if(x==a[m])  
		{   f=1;break;   }
		else if(x>a[m])  t=m+1;
		else                   b=m-1;
	}
	if(f==1)  cout<<"Yes,"<<m;
	else       cout<<"No";
}*/
#include<iostream>
using namespace std;
int main()
{
	int n,i,m,x,t,b,f,a[50];
	cin>>n;
	t=0;b=n-1;f=0;
	m=(t+b)/2;
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>x;
	while(t<=b)
	{
		if(x==a[m])
		{
			f=1;
			cout<<"a["<<m<<"]="<<x<<endl;
			break;
		}
			else if(x<a[m])
				b=m-1;
			else t=m+1;
			m=(t+b)/2;
	}
	if(f==0)cout<<"none"<<endl;
}