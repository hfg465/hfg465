#include<iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	int max(int,int);
		cout<<max(a,b)<<endl;
	return 0;
}
int max(int a,int b)
{
	if(a>=b)
		return a;
	else return b;
}