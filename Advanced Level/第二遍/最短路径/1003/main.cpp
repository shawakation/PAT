#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int n,startt,endt,men[maxn],graph[maxn][maxn]={0},dis[maxn],pathnum=0,maxmen=-1;
bool vis[maxn]={0};
vector<int> pre[maxn];
void calc()
{
	fill(dis,dis+maxn,INT_MAX);
	dis[startt]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=0;h<n;h++) if (dis[h]<minp&&vis[h]==0) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (graph[u][h]>0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int p,int mennum)
{
	if (p==startt) {
		pathnum++;
		maxmen=max(maxmen,mennum);
		return;
	}
	for (int h=0;h<pre[p].size();h++) search(pre[p][h],mennum+men[pre[p][h]]);
}
int main()
{
	int m;
	scanf("%d%d%d%d",&n,&m,&startt,&endt);
	for (int i=0;i<n;i++) scanf("%d",&men[i]);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	calc();
	search(endt,men[endt]);
	printf("%d %d",pathnum,maxmen);
	return 0;
}
