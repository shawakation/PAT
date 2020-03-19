#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<char*> > my;
bool cmp(char *a,char *b)
{
	return strcmp(a,b)<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		char *name=new char[7];
		int c;
		scanf("%s %d",name,&c);
		for (int j=0;j<c;j++) {
			int t;
			scanf("%d",&t);
			my[t].push_back(name);
		}
	}
	for (int i=1;i<=k;i++) {
		if (my.find(i)==my.end()) printf("%d 0\n",i);
		else {
			vector<char*> tt(my[i]);
			printf("%d %d\n",i,tt.size());
			sort(tt.begin(),tt.end(),cmp);
			for (auto &p:tt) printf("%s\n",p);
		}
	}
	return 0;
}
