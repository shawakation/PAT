#include <iostream>
#include <sstream>
using namespace std;
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
int main()
{
	string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	string s;
	int sum=0;
	cin>>s;
	for (int i=0;i<s.length();i++) sum+=s[i]-'0';
	string s1=inttostr(sum);
	for (int i=0;i<s1.length();i++) {
		cout<<arr[s1[i]-'0'];
		if (i!=s1.length()-1) cout<<' ';
	}
	return 0;
}

