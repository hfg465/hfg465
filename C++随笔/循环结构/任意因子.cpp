#include<iostream>
using namespace std;
int main()
{
	int x,i;
	float s,m;
	s=0;m=0;
	cin>>x;
	for(i=1;i<=x;i++)
		if(x%i==0)
		{
			s+=i;
			m++;
		}
		cout<<"s="<<s<<"\nm="<<m<<endl;
}