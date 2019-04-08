#include <bits/stdc++.h>
using namespace std;
string inttostr(long a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
long strtoint(string s)
{
	stringstream ss(s);
	long a;
	ss>>a;
	return a;
}
bool ishuiwen(string s)
{
	if (s=="0") return true;
	int k=s.length();
	for (int i=0;i<k/2;i++)
		if (s[i]!=s[k-i-1]) return false;
	return true;
}
int main()
{
	string num;
	cin>>num;
	int countt=0;
	if (ishuiwen(num)) {
		cout<<num<<" is a palindromic number.\n";
		return 0;
	}
	while (1) {
		long a=strtoint(num);
		string aa(num);
		reverse(num.begin(),num.end());
		long b=strtoint(num);
		string bb(num);
		string ss=inttostr(a+b);
		cout<<aa<<" + "<<bb<<" = "<<ss<<endl;
		num=ss;
		countt++;
		if (ishuiwen(num)) {
			cout<<num<<" is a palindromic number.\n";
			return 0;
		}
		if (countt==10) {
			cout<<"Not found in 10 iterations.\n";
			return 0;
		}
	}
	return 0;
}
