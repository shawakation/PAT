/*
26分。。。
1.问题出在排序，可能问题出在精度上
    过不了，有毒。。。
*/
#include <bits/stdc++.h>
#define maxn 1100
using namespace std;
const int inf=1e9;
int n=0,m=0,ds=0,graph[maxn][maxn]={0},dis[maxn]={0};
bool vis[maxn]={0};
unordered_map<string,int> nametonum;
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
void calc(int k)
{
	fill(dis,dis+maxn,inf);
	memset(vis,0,sizeof(vis));
	dis[k]=0;
	for (int y=1;y<=n+m;y++) {
		int u=-1,minp=inf;
		for (int h=1;h<=n+m;h++) if (vis[h]==0&&dis[h]<minp) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=1;h<=m+n;h++) if (graph[u][h]!=0&&vis[h]==0) {
				if (dis[h]>dis[u]+graph[u][h]) dis[h]=dis[u]+graph[u][h];
			}
	}
}
int main()
{
	int k;
	scanf("%d%d%d%d",&n,&m,&k,&ds);
	for (int i=n+1;i<=n+m;i++) {
		string s="G";
		s+=char(i-n+'0');
		nametonum[s]=i;
	}
	for (int i=0;i<k;i++) {
		string p1,p2;
		int dist,a,b;
		cin>>p1>>p2>>dist;
		if (p1[0]=='G') a=nametonum[p1];
		else a=strtoint(p1);
		if (p2[0]=='G') b=nametonum[p2];
		else b=strtoint(p2);
		graph[a][b]=graph[b][a]=dist;
	}
	int ansid=-1;
	double ansdis=-1,ansavg=inf;
	for (int i=n+1;i<=n+m;i++) {
		calc(i);
		double avgdis=0,mindis=inf;
		for (int j=1;j<=n;j++) {
			if (dis[j]>ds) {
				mindis=-1;
				break;
			}
			if (dis[j]<mindis) mindis=dis[j];
			avgdis+=1.0*dis[j]/n;
		}
		if (mindis==-1) continue;
		if (mindis>ansdis) {
			ansdis=mindis;
			ansavg=avgdis;
			ansid=i;
		}
		else if (mindis==ansdis) {
			if (ansavg>avgdis) {
				ansavg=avgdis;
				ansid=i;
			}
		}
	}
	if (ansid==-1) printf("No Solution\n");
	else printf("G%d\n%.1f %.1f\n",ansid-n,ansdis,ansavg);
	return 0;
}
