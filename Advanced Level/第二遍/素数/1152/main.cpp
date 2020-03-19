#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
	if (n<2) return 0;
	int sqr=(int)sqrt(n);
	for (int i=2;i<=sqr;i++) if (n%i==0) return 0;
	return 1;
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int main()
{
	int l,k;
	string s;
	cin>>l>>k>>s;
	if (l<k) cout<<"404";
	else {
		for (int i=0;i<=l-k;i++) {
			string s1=s.substr(i,k);
			if (isprime(strtoint(s1))) {
				cout<<s1;
				return 0;
			}
		}
		cout<<"404";
	}
	return 0;
}
