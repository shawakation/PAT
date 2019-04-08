#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll strtoll(string s)
{
	stringstream ss(s);
	ll a;
	ss>>a;
	return a;
}
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		string s;
		cin>>s;
		string s1=s.substr(0,s.length()/2);
		string s2=s.substr(s.length()/2,s.length()/2);
		ll product=strtoll(s1)*strtoll(s2);
		if (product==0) cout<<"No\n";
		else {
			ll remander=strtoll(s)%product;
			if (remander) cout<<"No\n";
			else cout<<"Yes\n";
		}
	}
	return 0;
}
