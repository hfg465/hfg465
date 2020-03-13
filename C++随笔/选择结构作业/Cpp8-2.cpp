#include<iostream>
using namespace std;
int main()
{
	int i,s;
	i=1;s=0;
	do
	{
		s+=i;
		i++;
	}
	while(i<=100);
		cout<<"s="<<s<<endl;
}
