/*
1.不难，理解题意是关键！
*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string s,max;
	int maxt=-1;
	unordered_map<string,int> my;
	getline(cin,s,'\n');
	int i=0;
	while (i<s.length()) {
		if (isalnum(s[i])) {
			int k=i+1;
			while (isalnum(s[k])&&k<s.length()) k++;
			string temp=s.substr(i,k-i);
			for (auto &t:temp) if (isalpha(t)&&isupper(t)) t=tolower(t);
			my[temp]++;
			i=k;
		} else i++;
	}
	for (auto it=my.begin(); it!=my.end(); it++)
		if (it->second>maxt) {
			maxt=it->second;
			max=it->first;
		}
	cout<<max<<' '<<maxt;
	return 0;
}
