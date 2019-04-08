/*
1.注意点：连通图！！！！
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int n,nodenum=0;
short graph[maxn][maxn]={0};
bool vis[maxn]={0};
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
	vector<int> arr(n+1);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a]++;
		arr[b]++;
		graph[a][b]=graph[b][a]=1;
	}
	int oddnum=0;
	for (int i=1;i<=n;i++) {
		if (arr[i]&1) oddnum++;
		printf("%d",arr[i]);
		if (i<n) printf(" ");
	}
	printf("\n");
	dfs(1);
	if (nodenum!=n) printf("Non-Eulerian\n");
	else {
		if (oddnum==0) printf("Eulerian\n");
		else if (oddnum==2) printf("Semi-Eulerian\n");
		else printf("Non-Eulerian\n");
	}
	return 0;
}
