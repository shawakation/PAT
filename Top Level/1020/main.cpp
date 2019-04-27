#include <bits/stdc++.h>
using namespace std;
unordered_set<string> ans;
int main()
{
	string s,s1;
	cin>>s;
	s1=s;
	ans.insert(s);
	for(int i=0; i<s.length(); i++) {
		s.erase(i,1);
		ans.insert(s);
		s=s1;
	}
	for(int i=0; i<s.length(); i++) {
		for(int j=0; j<s.length(); j++) {
			if(i!=j) {
				s.erase(i,1);
				s.erase(j,1);
				ans.insert(s);
				s=s1;
			}
		}
	}
	printf("%d\n",ans.size());
	return 0;
}
