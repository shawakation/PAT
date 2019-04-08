#include <bits/stdc++.h>
#define maxn 1020
using namespace std;
int n,m,Ds,dis[maxn],ans,mindis=-1,graph[maxn][maxn]={0};
double avgdis;
bool vis[maxn];
void calc(int k)
{
	fill(dis,dis+maxn,INT_MAX);
	memset(vis,0,sizeof(vis));
	dis[k]=0;
	for (int y=0;y<m+n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=1;h<=n+m;h++) if (dis[h]<minp&&vis[h]==0) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=1;h<=n+m;h++) if (graph[u][h]!=0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) dis[h]=dis[u]+graph[u][h];
		}
	}
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int tonum(string s)
{
	if (s[0]=='G') {
		s.erase(0,1);
		return n+strtoint(s);
	}
	else return strtoint(s);
}
int main()
{
	int k;
	scanf("%d%d%d%d",&n,&m,&k,&Ds);
	for (int i=0;i<k;i++) {
		string s1,s2;
		int cost;
		cin>>s1>>s2;
		scanf("%d",&cost);
		graph[tonum(s1)][tonum(s2)]=graph[tonum(s2)][tonum(s1)]=cost;
	}
	for (int i=1+n;i<=n+m;i++) {
		calc(i);
		int mindist=INT_MAX,totaldis=0;
		for (int j=1;j<=n;j++) {
			if (dis[j]>Ds) {
				mindist=-1;
				break;
			}
			mindist=min(mindist,dis[j]);
			totaldis+=dis[j];
		}
		if (mindist==-1) continue;
		double avgdist=(double)totaldis/(double)n;
		if (mindist>mindis) {
			mindis=mindist;
			avgdis=avgdist;
			ans=i;
		}
		else if (mindist==mindis) {
			if (avgdist<avgdis) {
				avgdis=avgdist;
				ans=i;
			}
		}
	}
	if (mindis==-1) printf("No Solution\n");
	else printf("G%d\n%.1f %.1f\n",ans-n,(float)mindis,avgdis);
	return 0;
}
