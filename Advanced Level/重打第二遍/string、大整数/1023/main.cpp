#include <bits/stdc++.h>
using namespace std;
unordered_map<char,int> my,my2;
string multi(string s,int a)
{
	int carry=0;
	string ans;
	for (int i=s.length()-1;i>=0;i--) {
		int t=(s[i]-'0')*a+carry;
		ans.insert(ans.begin(),char(t%10+'0'));
		carry=t/10;
	}
	while (carry>0) {
		ans.insert(ans.begin(),char(carry%10+'0'));
		carry/=10;
	}
	while (ans[0]=='0'&&ans.length()>1) ans.erase(0,1);
	return ans;
}
int main()
{
	string s;
	cin>>s;
	for (auto &p:s) my[p]++;
	string s2=multi(s,2);
	for (auto &p:s2) my2[p]++;
	if (my.size()!=my2.size()) {
		printf("No\n%s",s2.c_str());
		return 0;
	}
	for (auto &p:my) {
		if (my2.find(p.first)==my2.end()) {
			printf("No\n%s",s2.c_str());
			return 0;
		}
		else if (my2[p.first]!=p.second) {
			printf("No\n%s",s2.c_str());
			return 0;
		}
	}
	printf("Yes\n%s",s2.c_str());
	return 0;
}
