#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,j;
	j=0;
	cin>>n;
	for(i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
			j++;
	}
	if(j==1&&n!=1)
		cout<<n<<"   yes\n";
	else cout<<n<<"   no\n";
}
