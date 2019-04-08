#include <bits/stdc++.h>
using namespace std;
unordered_map<string,vector<int> > my;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0;i<k;i++) {
		int id,num;
		scanf("%d%d",&id,&num);
		for (int j=0;j<num;j++) {
			char name[7];
			scanf("%s",name);
			string s(name);
			my[s].push_back(id);
		}
	}
	for (int i=0;i<n;i++) {
		char query[7];
		scanf("%s",query);
		string s(query);
		if (my.find(s)==my.end()) printf("%s 0\n",query);
		else {
			vector<int> tt(my[s]);
			sort(tt.begin(),tt.end());
			printf("%s %d",query,tt.size());
			for (auto &p:tt) printf(" %d",p);
			printf("\n");
		}
	}
	return 0;
}
