#include <bits/stdc++.h>
#define maxn 20
using namespace std;
short graph[maxn][maxn]= {0};
bool vis[maxn];
int n;
void dfs(int p)
{
	vis[p]=1;
	printf(" %d",p);
	for (int h=0; h<n; h++) if (graph[p][h]==1&&vis[h]==0) dfs(h);
}
void bfs(int p)
{
	queue<int> q;
	vis[p]=1;
	q.push(p);
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		printf(" %d",t);
		for (int h=0; h<n; h++) if (graph[t][h]==1&&vis[h]==0) {
				vis[h]=1;
				q.push(h);
			}
	}
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	memset(vis,0,sizeof(vis));
	for (int i=0; i<n; i++) if (vis[i]==0) {
			printf("{");
			dfs(i);
			printf(" }\n");
		}
	memset(vis,0,sizeof(vis));
	for (int i=0; i<n; i++) if (vis[i]==0) {
			printf("{");
			bfs(i);
			printf(" }\n");
		}
	return 0;
}
