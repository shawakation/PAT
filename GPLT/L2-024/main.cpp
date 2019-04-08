#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
int n;
unordered_set<int> graph[maxn];
bool vis[maxn]={0};
vector<pair<int,int> > bb;
void restore()
{
	while (!bb.empty()) {
		pair<int,int> tt=bb[bb.size()-1];
		graph[tt.first].insert(tt.second);
		graph[tt.second].insert(tt.first);
		bb.pop_back();
	}
}
void dfs(int k)
{
	vis[k]=1;
	for (auto &p:graph[k]) if (vis[p]==0) dfs(p);
}
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int t;
		scanf("%d",&t);
		for (int j=0;j<t;j++) {
			int lost;
			scanf("%d",&lost);
			for (auto &p:graph[lost]) {
				bb.push_back(make_pair(lost,p));
				graph[p].erase(lost);
			}
			graph[lost].clear();
		}
		int countt=0;
		memset(vis,0,sizeof(vis));
		for (int j=1;j<=n;j++) if (vis[j]==0) {
			countt++;
			dfs(j);
		}
		if (countt==n) printf("YES\n");
		else printf("NO\n");
		if (i<k-1) restore();
	}
	return 0;
}
