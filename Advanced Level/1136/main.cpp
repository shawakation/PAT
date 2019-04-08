#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string add(string a,string b)
{
	int maxlen=max(a.length(),b.length());
	while (a.length()<maxlen) a.insert(0,"0");
	while (b.length()<maxlen) b.insert(0,"0");
	int carry=0;
	string ans;
	for (int i=maxlen-1;i>=0;i--) {
		int t=(a[i]-'0')+(b[i]-'0')+carry;
		ans.insert(ans.begin(),char(t%10+'0'));
		carry=t/10;
	}
	if (carry>0) ans.insert(ans.begin(),char(carry%10+'0'));
	return ans;
}
bool ispra(string s)
{
	int len=s.length();
	int n=s.length()/2-1;
	for (int i=0;i<=n;i++) if (s[i]!=s[len-i-1]) return 0;
	return 1;
}
int main()
{
	string s;
	int countt=0;
	cin>>s;
	while (!ispra(s)&&countt<10) {
		string s1=s;
		reverse(s.begin(),s.end());
		string s2=add(s1,s);
		cout<<s1<<" + "<<s<<" = "<<s2<<endl;
		s=s2;
		countt++;
	}
	if (countt<10) cout<<s<<" is a palindromic number.\n";
	else cout<<"Not found in 10 iterations.\n";
	return 0;
}
