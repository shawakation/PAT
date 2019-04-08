/*
12分，不知道问题。。。
*/
#include <bits/stdc++.h>
using namespace std;
bool isprintt[300]={0};
int main()
{
	int k;
	string s,ans;
	unordered_map<char,bool> my;
	cin>>k;
	cin.ignore();
	getline(cin,s,'\n');
	for (int i=0;i<s.length();) {
		int j=i+1;
		while (s[j]==s[i]&&j<s.length()&&j-i<k) j++;
		if (j-i==k) {
			if (my.find(s[i])==my.end()) my[s[i]]=1;
 		}
		else my[s[i]]=0;
		i=j;
	}
	for (int i=0;i<s.length();i++)
		if (my[s[i]]) {
			s.erase(i,2);
			if (isprintt[s[i]]==0) {
				ans+=s[i];
				isprintt[s[i]]=1;
			}
		}
 	cout<<ans<<endl<<s<<endl;
	return 0;
}
