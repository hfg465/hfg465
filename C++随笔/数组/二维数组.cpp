#include<iostream>
using namespace std;
int main()
{
	int a[3][4],i,k;
	for(i=0;i<3;i++)
		for(k=0;k<4;k++)
			cin>>a[i][k];
		for(i=0;i<3;i++)
		{
			for(k=0;k<4;k++)
				cout<<a[i][k]<<" ";
			cout<<"\n";
		}
}