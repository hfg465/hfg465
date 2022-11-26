#include <cmath>
#include <iostream>
using namespace std;
int main()
{
	int n,j,k,f;
	cin>>n;
	k=sqrt(n),j=2,f=1;
	while(j<=k)
		if(n%j!=0)
			j++;
		else
		{
			f=0;
			break;
		}
	if(f==1)
		cout<<n<<"  yes\n";
	else
		cout<<n<<"  no\n";
}
