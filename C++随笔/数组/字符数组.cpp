/*输入5个小写字母，将其用原来的字母后面第4个字母代替。例如，字母‘a’译成‘e’ ；字母
‘x’译成‘b’。*/
#include<iostream>
using namespace std;
int main()
{
	char a[20],i;
	cin>>a;
	for(i=0;a[i]!=0;i++)
	{
		a[i]+=4;
		if(a[i]>'z')
			a[i]-=26;
	}
	cout<<a<<endl;
}
