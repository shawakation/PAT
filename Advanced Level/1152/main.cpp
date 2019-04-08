#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int strtoint(string s)
{
	stringstream ss(s);
	int temp;
	ss>>temp;
	return temp;
}
bool isprime(int n)
{
	if (n==0||n==1) return 0;
	for (int k=2;k*k<=n;k++)
		if (n%k==0) return 0;
	return 1;
}
int main()
{
	int l,k;
	string s;
	cin>>l>>k;
	cin>>s;
	for (int i=0;i<=l-k;i++) {
		string ss=s.substr(i,k);
		int num=stoi(ss);
		if (isprime(num)) {
			cout<<num;
			return 0;
		}
	}
	cout<<"404";
	return 0;
}
