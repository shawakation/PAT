#include <cstdio>
#include <algorithm>
#include <climits>
#include <memory.h>
#define maxn 110
using namespace std;
int graph[maxn][maxn]= {0},dis[maxn],minpath=INT_MAX,n,ans=-1;
bool vis[maxn];
int calc(int s)
{
	int maxlen=-1;
	fill(dis,dis+n+1,INT_MAX);
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	while (1) {
		int u=-1,minp=INT_MAX;
		for (int h=1; h<=n; h++) if (vis[h]==0&&dis[h]<minp) {
				minp=dis[h];
				u=h;
			}
		if (u==-1) {
			for (int h=1; h<=n; h++) maxlen=max(maxlen,dis[h]);
			return maxlen;
		}
		vis[u]=1;
		for (int h=1; h<=n; h++) if (vis[h]==0&&graph[u][h]>0)
				dis[h]=min(dis[h],graph[u][h]+dis[u]);
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	for (int i=1; i<=n; i++) {
		int minp=calc(i);
		if (minp==INT_MAX) continue;
		if (minp<minpath) {
			minpath=minp;
			ans=i;
		}
	}
	if (ans==-1) printf("0\n");
	else printf("%d %d\n",ans,minpath);
	return 0;
}
