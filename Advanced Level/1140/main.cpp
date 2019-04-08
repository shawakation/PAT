#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	string s;
	s+=char(n+'0');
	for (int i=1;i<k;i++) {
		string s2;
		int j=0,h=0;
		while (j<s.length()) {
			while (s[h]==s[j]&&h<s.length()) h++;
			s2+=s[j];
			s2+=char(h-j+'0');
			j=h;
		}
		s=s2;
	}
	cout<<s;
	return 0;
}
