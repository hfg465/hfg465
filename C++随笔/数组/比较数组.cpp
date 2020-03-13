#include<iostream>
using namespace std;
int main()
{
	char a[50],s[50];
	int c,i;
	cin>>a>>s;
	for(i=0;a[i]==s[i];i++)
		if(a[i]=='\0')break;
		c=a[i]-s[i];
		if(c<0)c=-c;
		cout<<c<<endl;
		if(a==s)
			cout<<"0"<<endl;
}