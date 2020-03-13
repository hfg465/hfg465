#include<iostream>
using namespace std;
float he(float x,float y)
{
	float z;
	z=x+y;
	return z;
}
int main()
{
	float a,b,s;
	cin>>a>>b;
	s=he(a,b);
	cout<<s<<endl;
}