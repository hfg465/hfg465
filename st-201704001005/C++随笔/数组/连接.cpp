/*#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char t1[50],t2[50];
	cin>>t1>>t2;
	strcat(t1,t2);
	cout<<t1<<endl;
}
*/
#include<iostream>
using namespace std;
int main()
{
	char a[50],s[50];
	int i,k,e,d,b;
	cin>>a>>s;
	d=0;                      //»ò#include<cstring>;d=strlen(a);
	while(a[d]!=0)
		d++;
	i=0;
	while(s[i]!=0)
	{
		a[d]=s[i];
		d++;
		i++;
	}
	a[d]='\0';
	cout<<a<<endl;
}