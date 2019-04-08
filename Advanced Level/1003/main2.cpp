/*
	解法二：Dijstkra+DFS  Dijstkra 计算所有最短路径，DFS 找出第二条件最优路径
	    代码量稍多，但最短路径算法固定，可以当模版用
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
const int INF=1e9;
int n=0,startt=0,endt=0,num=0,optw=-1;
int graph[maxn][maxn]={0},path[maxn]={0},weight[maxn]={0};
bool vis[maxn]={0};
vector<int> pre[maxn],tempp,ans;
void calc(int k)
{
	fill(path,path+maxn,INF);
	path[k]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INF;
		for (int h=0;h<n;h++) if (vis[h]==0&&path[h]<minp) {
			u=h;
			minp=path[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++)
			if (graph[u][h]!=0&&vis[h]==0) {
				if (path[h]>graph[u][h]+path[u]) {
					path[h]=graph[u][h]+path[u];
					pre[h].clear();
					pre[h].push_back(u);
				}
				else if (path[h]==graph[u][h]+path[u]) pre[h].push_back(u);
			}
	}
}
void search(int k)
{
	tempp.push_back(k);
	if (k==startt) {
		num++;
		int totalw=0;
		for (int h=0;h<tempp.size();h++) totalw+=weight[tempp[h]];
		if (totalw>optw) optw=totalw;
		tempp.pop_back();
		return;
	}
	for (int j=0;j<pre[k].size();j++) search(pre[k][j]);
	tempp.pop_back();
}
int main()
{
	int m;
	scanf("%d%d%d%d",&n,&m,&startt,&endt);
	for (int i=0;i<n;i++) scanf("%d",&weight[i]);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	calc(startt);
	search(endt);
	printf("%d %d\n",num,optw);
	return 0;
}
