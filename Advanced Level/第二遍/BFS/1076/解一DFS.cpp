#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int n,l,num;
short graph[maxn][maxn]={0};
bool vis[maxn];
void search(int p,int layer)
{
	if (layer>l) return;
	vis[p]=1;
	num++;
	for (int h=1;h<=n;h++) if (graph[p][h]==1&&vis[h]==0) search(h,layer+1);
}
int main()
{
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++) {
			int t;
			scanf("%d",&t);
			graph[t][i]=1;
		}
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int query;
		scanf("%d",&query);
		memset(vis,0,sizeof(vis));
		num=0;
		search(query,0);
		printf("%d\n",num-1);
	}
	return 0;
}
