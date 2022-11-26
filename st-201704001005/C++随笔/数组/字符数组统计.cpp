#include<iostream>
using namespace std;
int main()
{
	char s[50];
	int zm,qt,sz,i;
	zm=qt=sz=0;
	cin>>s;
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]<='z'&&s[i]>='a')||(s[i]>='A')&&s[i]<='Z')
			zm++;
		else if(s[i]>='0'&&s[i]<='9')
			sz++;
		else qt++;
	}
	cout<<"zm="<<zm<<" "<<"sz="<<sz<<" "<<"qt="<<qt;
	cout<<endl;
}