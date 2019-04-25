#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int father[maxn];
unordered_set<int> my[maxn];
unordered_map<int,int> tt;
void init(int n)
{
	for (int i=1;i<=n;i++) father[i]=i;
}
int find(int x)
{
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
int main()
{
	int n;
	scanf("%d",&n);
	init(n);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d: ",&k);
		for (int j=0;j<k;j++) {
			int t;
			scanf("%d",&t);
			if (!my[t].empty()) unit(*(my[t].begin()),i);
			my[t].insert(i);
		}
	}
	for (int i=1;i<=n;i++) tt[find(i)]++;
	vector<int> ans;
	for (auto &p:tt) ans.push_back(p.second);
	sort(ans.begin(),ans.end(),greater<int>());
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	return 0;
}
