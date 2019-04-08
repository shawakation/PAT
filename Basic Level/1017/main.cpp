#include <bits/stdc++.h>
using namespace std;
string divide(string s,int q,int &r)
{
	string ans;
	for (int i=0;i<s.length();i++) {
		r=r*10+s[i]-'0';
		if (r<q) ans+="0";
		else {
			ans+=char(r/q+'0');
			r%=q;
		}
	}
	while (ans[0]=='0'&&ans.length()>1) ans.erase(0,1);
	return ans;
}
int main()
{
	string s;
	int a,r=0;
	cin>>s>>a;
	cout<<divide(s,a,r)<<' ';
	cout<<r;
	return 0;
}
