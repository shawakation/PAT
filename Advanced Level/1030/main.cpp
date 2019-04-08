#include <bits/stdc++.h>
#define maxn 510
using namespace std;
const int inf=1e9;
int n=0,startt=0,endt=0,path[maxn]={0},mincost=inf;
short highway[maxn][maxn]={0},costs[maxn][maxn]={0};
bool vis[maxn]={0};
vector<int> pre[maxn],ans,tempp;
void calc(int k)
{
	fill(path,path+maxn,inf);
	path[k]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=inf;
		for (int h=0;h<n;h++) if (vis[h]==0&&path[h]<minp) {
			u=h;
			minp=path[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (highway[u][h]!=0&&vis[h]==0) {
			if (path[h]>path[u]+highway[u][h]) {
				path[h]=path[u]+highway[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (path[h]==path[u]+highway[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int k,int cost)
{
	tempp.push_back(k);
	if (k==startt) {
		if (mincost>cost) {
			mincost=cost;
			ans=tempp;
		}
		tempp.pop_back();
		return;
	}
	for (int h=0;h<pre[k].size();h++) search(pre[k][h],cost+costs[k][pre[k][h]]);
	tempp.pop_back();
}
int main()
{
	int m;
	scanf("%d%d%d%d",&n,&m,&startt,&endt);
	for (int i=0;i<m;i++) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		highway[a][b]=highway[b][a]=c;
		costs[a][b]=costs[b][a]=d;
	}
	calc(startt);
	search(endt,0);
	for (int i=ans.size()-1;i>=0;i--) printf("%d ",ans[i]);
	printf("%d %d\n",path[endt],mincost);
	return 0;
}
