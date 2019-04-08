#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int n,startt,endt,dis[maxn],mincost=INT_MAX;
short graph[maxn][maxn]={0},cost[maxn][maxn]={0};
bool vis[maxn]={0};
vector<int> pre[maxn];
void calc(int k)
{
	fill(dis,dis+maxn,INT_MAX);
	dis[k]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=0;h<n;h++) if (vis[h]==0&&dis[h]<minp) {
			minp=dis[h];
			u=h;
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (vis[h]==0&&graph[u][h]!=0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int k,int costs)
{
	if (k==startt) {
		if (costs<mincost) mincost=costs;
		return;
	}
	for (int h=0;h<pre[k].size();h++) search(pre[k][h],costs+cost[k][pre[k][h]]);
}
int main()
{
	int m;
	scanf("%d%d%d%d",&n,&m,&startt,&endt);
	for (int i=0;i<m;i++) {
		int a,b,l,c;
		scanf("%d%d%d%d",&a,&b,&l,&c);
		graph[a][b]=graph[b][a]=l;
		cost[a][b]=cost[b][a]=c;
	}
	calc(startt);
	search(endt,0);
	printf("%d %d",dis[endt],mincost);
	return 0;
}
