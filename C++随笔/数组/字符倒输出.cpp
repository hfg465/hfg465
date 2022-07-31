#include<iostream>
using namespace std;
int main()
{
	char s[50];
	int i,b,e,t,p;
	cin>>s;
	b=0;
	while(s[b]!='\0')
		b++;
	e=0;t=b-1;
	while(e<t)
	{
		p=s[e];s[e]=s[t];s[t]=p;
		e++;t--;
	}
	cout<<s<<endl;
}