#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int l,n;
	string ss="";
	cin>>l>>n;
	long long num=pow(26,l)-n;
	while (num!=0) {
		int yu=num%26;
		ss+=(char)(yu+'a');
		num/=26;
	}
	for (int i=l-ss.length();i>0;i--) ss+='a';
	reverse(ss.begin(),ss.end());
	cout<<ss;
	return 0;
}
