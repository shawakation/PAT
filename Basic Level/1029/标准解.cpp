#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s1,s2,broken;
	cin>>s1>>s2;
	for (int i=0;i<s1.length();i++) {
		if (s2.find(s1[i])==string::npos&&broken.find(toupper(s1[i]))==string::npos)
			broken+=toupper(s1[i]);
	}
	cout<<broken;
	return 0;
}
