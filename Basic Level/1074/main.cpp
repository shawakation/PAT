#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int strtonum(string ss)
{
	stringstream ssr(ss);
	int temp;
	ssr>>temp;
	return temp;
}
int main()
{
	string s,s1,s2,ans;
	cin>>s>>s1>>s2;
	int carry=0;
	string ss1(s.length()-s1.length(),'0');
	string ss2(s.length()-s2.length(),'0');
	s1=ss1+s1;
	s2=ss2+s2;
	for (int i=s.length()-1;i>=0;i--) {
		int mod=(s[i]=='0')?10:(s[i]-'0');
		int num=(s1[i]-'0'+s2[i]-'0'+carry)%mod;
		carry=(s1[i]-'0'+s2[i]-'0'+carry)/mod;
		ans.insert(0,to_string(num));
	}
	if (carry!=0) ans.insert(0,"1");
	cout<<strtonum(ans);
	return 0;
}
