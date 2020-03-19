#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int n,l,layer[maxn];
short graph[maxn][maxn]={0};
bool vis[maxn];
int search(int p)
{
	int nodenum=0;
	layer[p]=0;
	vis[p]=1;
	queue<int> q;
	q.push(p);
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		for (int h=1;h<=n;h++) if (graph[t][h]==1&&vis[h]==0) {
			layer[h]=layer[t]+1;
			if (layer[h]<=l) {
				vis[h]=1;
				q.push(h);
				nodenum++;
			}
		}
	}
	return nodenum;
}
int main()
{
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++) {
			int t;
			scanf("%d",&t);
			graph[t][i]=1;
		}
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int query;
		scanf("%d",&query);
		memset(vis,0,sizeof(vis));
		memset(layer,0,sizeof(layer));
		printf("%d\n",search(query));
	}
	return 0;
}
