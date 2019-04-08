#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int main()
{
	string s;
	bool flag=false;
	int i;
	cin>>s;
	if (s[0]=='-') cout<<'-';
	string subs="";
	string exp="";
	subs+=s[1];
	for (i=3;s[i]!='E';i++) {
		subs+=s[i];
	}
	i++;
	if (s[i]=='-') flag=true;
	i++;
	for (;i<s.length();i++) {
		exp+=s[i];
	}
	int expo=strtoint(exp);
	if (flag) {
		for (int k=0;k<expo-1;k++) subs.insert(0,"0");
		subs.insert(0,"0.");
	}
	else {
		if (expo<subs.length()) subs.insert(expo+1,".");
		else subs.append(expo-subs.length()+1,'0');
	}
	cout<<subs;
	return 0;
}
