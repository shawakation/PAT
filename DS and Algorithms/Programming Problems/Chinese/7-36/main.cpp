#include <bits/stdc++.h>
#define maxn 10005
using namespace std;
unordered_set<int> graph[maxn];
int n,dis[maxn];
bool vis[maxn];
struct cmp {
	bool operator () (int a,int b) const {
		return dis[a]>dis[b];
	}
};
bool calc(int k)
{
	fill(dis,dis+n+1,INT_MAX);
	memset(vis,0,sizeof(vis));
	priority_queue<int,vector<int>,cmp> qu;
	dis[k]=0;
	qu.push(k);
	for (int y=1; y<=n; y++) {
		while (!qu.empty()&&vis[qu.top()]) qu.pop();
		if (qu.empty()) return 0;
		int u=qu.top();
		qu.pop();
		vis[u]=1;
		for (int p:graph[u])
			if (vis[p]==0) {
				if (dis[u]+1<dis[p]) {
					dis[p]=dis[u]+1;
					qu.push(p);
				}
			}
	}
	return 1;
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
		int q;
		scanf("%d",&q);
		if (calc(q)) {
			int sum=0;
			for (int j=1;j<=n;j++) sum+=dis[j];
			printf("Cc(%d)=%.2f\n",q,(float)(n-1)/(float)sum);
		}
		else printf("Cc(%d)=0.00\n",q);
	}
	return 0;
}