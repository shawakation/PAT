#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
short graph[maxn][maxn]={0},degree[maxn]={0};
bool vis[maxn]={0};
int n,nodenum=0;
void dfs(int k)
{
	vis[k]=1;
	nodenum++;
	for (int h=1;h<=n;h++) if (vis[h]==0&&graph[k][h]==1) dfs(h);
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
		degree[a]++;
		degree[b]++;
	}
	dfs(1);
	if (nodenum==n) {
		int oddnum=0;
		for (int i=1;i<=n;i++) if (degree[i]&1) oddnum++;
		if (oddnum==0) printf("1");
		else printf("0");
	}
	else printf("0");
	return 0;
}
