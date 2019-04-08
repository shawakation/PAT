#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string add(string a,string b)
{
	int maxlen=max(a.length(),b.length());
	while (a.length()<maxlen) a.insert(a.begin(),'0');
	while (b.length()<maxlen) b.insert(b.begin(),'0');
	string ans;
	int carry=0;
	for (int i=maxlen-1; i>=0; i--) {
		int t=a[i]-'0'+b[i]-'0'+carry;
		ans.insert(ans.begin(),(char)(t%10+'0'));
		carry=t/10;
	}
	if (carry>0) ans.insert(ans.begin(),char(carry+'0'));
	return ans;
}
bool ispra(string s)
{
	int n=s.length();
	int a=n/2-1;
	for (int i=0; i<=a; i++)
		if (s[i]!=s[n-i-1]) return 0;
	return 1;
}
int main()
{
	string s;
	int k,countt=0;
	cin>>s>>k;
	while (!ispra(s)&&countt<k) {
		string s1=s;
		reverse(s1.begin(),s1.end());
		s=add(s1,s);
		countt++;
	}
	cout<<s<<endl<<countt<<endl;
	return 0;
}
