#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int n,startt,endt,dis[maxn],mincost=INT_MAX;
bool vis[maxn]={0};
short graph[maxn][maxn]={0},cost[maxn][maxn]={0};
vector<int> pre[maxn],temp,ans;
void calc(int p)
{
	fill(dis,dis+maxn,INT_MAX);
	dis[p]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=0;h<n;h++) if (vis[h]==0&&dis[h]<minp) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (vis[h]==0&&graph[u][h]>0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int p,int c)
{
	temp.push_back(p);
	if (p==startt) {
		if (c<mincost) {
			mincost=c;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	for (int i=0;i<pre[p].size();i++) search(pre[p][i],c+cost[p][pre[p][i]]);
	temp.pop_back();
}
int main()
{
	int m;
	scanf("%d%d%d%d",&n,&m,&startt,&endt);
	for (int i=0;i<m;i++) {
		int a,b,d,c;
		scanf("%d%d%d%d",&a,&b,&d,&c);
		graph[a][b]=graph[b][a]=d;
		cost[a][b]=cost[b][a]=c;
	}
	calc(startt);
	search(endt,0);
	for (int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	printf("%d %d",dis[endt],mincost);
	return 0;
}
