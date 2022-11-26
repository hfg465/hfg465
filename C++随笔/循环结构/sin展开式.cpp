#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i;
	float x,t,m,q,s;
	cin>>n>>x;
	t=-1;q=1;s=1;
	for(i=1;i<=n;i++)
	{
		t=-t;
		m=pow(x,i);
		q*=i;
		s+=t*m/q;
	}
	cout<<s<<endl;
}