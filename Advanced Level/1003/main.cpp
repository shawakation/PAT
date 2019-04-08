/*
        解法一：纯 Dijtskra
1.注意点一：path 初始化为 INF 时不要直接初始化，会出问题
            用 fill 函数填充
2.注意点二：记录结点个数和权值的条件要记住，每个条件都要写
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
const int INF=1e9;
int city=0,init=0,endt=0,graph[maxn][maxn]={0};
int men[maxn]={0},pathnum[maxn]={0},maxmen[maxn],path[maxn];
bool isvisit[maxn]={0};
void calc(int k)
{
	fill(path,path+maxn,INF);
	pathnum[k]=1;
	path[k]=0;
	maxmen[k]=men[k];
	for (int y=0;y<city;y++) {
		int u=-1,minpath=INF;
		for (int h=0;h<city;h++)
			if (isvisit[h]==0&&path[h]<minpath) {
				u=h;
				minpath=path[h];
			}
		if (u==-1) return;
		isvisit[u]=1;
		for (int h=0;h<city;h++)
			if (graph[u][h]!=0&&isvisit[h]==0) {
				if (path[h]>path[u]+graph[u][h]) {
					path[h]=path[u]+graph[u][h];
					pathnum[h]=pathnum[u];
					maxmen[h]=maxmen[u]+men[h];
				}
				else if (path[h]==path[u]+graph[u][h]) {
					if (maxmen[h]<maxmen[u]+men[h]) maxmen[h]=maxmen[u]+men[h];
					pathnum[h]+=pathnum[u];
				}
			}
	}
}
int main()
{
	int m;
	scanf("%d%d%d%d",&city,&m,&init,&endt);
	for (int i=0;i<city;i++) scanf("%d",&men[i]);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	calc(init);
	printf("%d %d\n",pathnum[endt],maxmen[endt]);
	return 0;
}
