#include <bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
	while (a.length()<b.length()) a.insert(0,"0");
	while (b.length()<a.length()) b.insert(0,"0");
	int len=a.length(),carry=0;
	string ans;
	for (int i=len-1;i>=0;i--) {
		int t=a[i]-'0'+b[i]-'0'+carry;
		ans.insert(ans.begin(),char(t%10+'0'));
		carry=t/10;
	}
	if (carry>0) ans.insert(ans.begin(),char(carry+'0'));
	return ans;
}
bool istrue(string s)
{
	int len=s.length();
	for (int i=0;i<=len/2-1;i++) if (s[i]!=s[len-1-i]) return 0;
	return 1;
}
int main()
{
	string s;
	cin>>s;
	int countt=0;
	while (!istrue(s)&&countt<10) {
		string s2=s;
		reverse(s.begin(),s.end());
		string s3=add(s2,s);
		printf("%s + %s = %s\n",s2.c_str(),s.c_str(),s3.c_str());
		s=s3;
		countt++;
	}
	if (countt<10) printf("%s is a palindromic number.\n",s.c_str());
	else printf("Not found in 10 iterations.\n");
	return 0;
}
