/*
1.20分。。。知道了，原来是题意没弄透
            本题不能用简单的累加车总数和应当的数量比较来确定带走还是带回
            因为本题要求只能向前走到终点然后返回，而不是可以在路程中来回往返
            并且往回走时各车站不再做调整
            因此只能通过遍历路径模拟的方式进行
2.可以把 bike 数组设成 w-c/2 为正表示需要带走，为负表示需要带来
3.当最小 need 满足的时候也要赋值 minback 否则会出错（虽然不知道为什么。。）
4.这道题是超难题，有时间再打一遍
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
const int inf=1e9;
int c=0,n=0,endt=0,graph[maxn][maxn]={0},bike[maxn]={0},dis[maxn]={0};
int minsend=inf,minback=inf,send=0,back=0;
bool vis[maxn]={0};
vector<int> pre[maxn],tempp,ans;
void calc(int k)
{
	fill(dis,dis+maxn,inf);
	dis[k]=0;
	for (int y=0;y<=n;y++) {
		int u=-1,minp=inf;
		for (int h=0;h<=n;h++) if (dis[h]<minp&&vis[h]==0) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<=n;h++) if (graph[u][h]!=0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int k)
{
	tempp.push_back(k);
	if (k==0) {
		send=back=0;
		for (int g=tempp.size()-2;g>=0;g--) {
			if (bike[tempp[g]]>0) back+=bike[tempp[g]];
			else if (bike[tempp[g]]<0) {
				if (back>=abs(bike[tempp[g]])) back-=abs(bike[tempp[g]]);
				else {
					send+=abs(bike[tempp[g]])-back;
					back=0;
				}
			}
		}
		if (send<minsend) {
			minsend=send;
			minback=back;
			ans=tempp;
		}
		else if (send==minsend) {
			if (back<minback) {
				minback=back;
				ans=tempp;
			}
		}
		tempp.pop_back();
		return;
	}
	for (int j=0;j<pre[k].size();j++) search(pre[k][j]);
	tempp.pop_back();
}
int main()
{
	int m;
	scanf("%d%d%d%d",&c,&n,&endt,&m);
	for (int i=1;i<=n;i++) {
		int w;
		scanf("%d",&w);
		bike[i]=w-c/2;
	}
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	calc(0);
	search(endt);
	printf("%d ",minsend);
	for (int i=ans.size()-1;i>=0;i--) {
		printf("%d",ans[i]);
		if (i>0) printf("->");
	}
	printf(" %d\n",minback);
	return 0;
}
