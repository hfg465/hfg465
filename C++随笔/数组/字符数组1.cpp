#include<iostream>
using namespace std;
int main()
{
	char a[20];
	int i;
	cin>>a;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='a'&&a[i]<='z')
		{
			a[i]+=4;
			if(a[i]>'z')
				a[i]-=26;
		}
		if(a[i]<='Z'&&a[i]>='A')
		{
			a[i]+=4;
			if(a[i]>'Z')
				a[i]-=26;
		}
	}
		cout<<a<<endl;
}