#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main()
{
	string s1,s2;
	unordered_set<char> my;
	getline(cin,s1,'\n');
	getline(cin,s2,'\n');
	for (int i=0;i<s2.length();i++) my.insert(s2[i]);
	for (int i=0;i<s1.length();i++)
		if (my.find(s1[i])==my.end()) printf("%c",s1[i]);
	return 0;
}
