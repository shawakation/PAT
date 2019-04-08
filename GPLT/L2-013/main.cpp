/*
注意点：保存结果，判断大于
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int n,countt=0;
short graph[maxn][maxn]={0};
bool vis[maxn]={0};
unordered_set<int> haslost;
void dfs(int k)
{
	vis[k]=1;
	for (int h=0;h<n;h++) if (graph[k][h]==1&&vis[h]==0) dfs(h);
}
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	for (int i=0;i<n;i++) if (vis[i]==0) {
		countt++;
		dfs(i);
	}
	scanf("%d",&k);
	int islost=0;
	for (int i=0;i<k;i++) {
		int c,num=0;
		scanf("%d",&c);
		memset(vis,0,sizeof(vis));
		haslost.insert(c);
		for (int j=0;j<n;j++) if (graph[c][j]==1) graph[c][j]=graph[j][c]=0;
		for (int b=0;b<n;b++) if (vis[b]==0&&haslost.find(b)==haslost.end()) {
			num++;
			dfs(b);
		}
		if (num>countt) printf("Red Alert: City %d is lost!\n",c);
		else printf("City %d is lost.\n",c);
		countt=num;
	}
	if (haslost.size()==n) printf("Game Over.\n");
	return 0;
}
