#include <bits/stdc++.h>
using namespace std;
vector<int> father;
int n=0;
unordered_map<int,int> ans;
vector<int> anss;
bool cmp(int a,int b)
{
	return a>b;
}
void init()
{
	father.resize(n+1);
	for (int i=1; i<=n; i++) father[i]=i;
}
int find(int x)
{
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void unit(int a,int b)
{
	int af=find(a),bf=find(b);
	if (af!=bf) father[af]=bf;
}
int main()
{
	scanf("%d",&n);
	init();
	unordered_map<int,vector<int> > my;
	for (int i=1; i<=n; i++) {
		int t;
		scanf("%d: ",&t);
		for (int j=0; j<t; j++) {
			int tt;
			scanf("%d",&tt);
			if (my.find(tt)!=my.end())
				for (int k=0; k<my[tt].size(); k++) unit(my[tt].at(k),i);
			my[tt].push_back(i);
		}
	}
	for (int i=1; i<=n; i++) ans[find(i)]++;
	for (auto p:ans) anss.push_back(p.second);
	sort(anss.begin(),anss.end(),cmp);
	printf("%d\n",anss.size());
	for (int i=0; i<anss.size(); i++) {
		printf("%d",anss[i]);
		if (i<anss.size()-1) printf(" ");
	}
	printf("\n");
	return 0;
}
