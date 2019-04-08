#include <bits/stdc++.h>
using namespace std;
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
int main()
{
	char c;
	string s;
	cin>>c;
	cin.ignore();
	getline(cin,s,'\n');
	if (c=='C') {       //compress
		string overcome="";
		for (int i=0;i<s.length();) {
			int j=i;
			while (s[j]==s[i]&&j<s.length()) j++;
			int k=j-i;
			if (k==1) overcome+=s[i];
			else if (k>1) {
				overcome.insert(overcome.length(),inttostr(k));
				overcome+=s[i];
			}
			i=j;
		}
		cout<<overcome;
	}
	else if (c=='D') {      //decompress
		string overcome="";
		for (int i=0;i<s.length();) {
			if (isdigit(s[i])) {
				int j=i;
				while (isdigit(s[j])) j++;
				int aa=strtoint(s.substr(i,j-i));
				overcome.append(aa,s[j]);
				i=j+1;
			}
			else if (isalpha(s[i])||isblank(s[i])) {
				overcome+=s[i];
				i++;
			}
		}
		cout<<overcome;
	}
	return 0;
}
