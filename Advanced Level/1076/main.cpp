/*
1.题意理解问题，开始题意没有理解正确。。。
2.题目中出现了类似 层数 level 这样的建议优先用 bfs
3.dfs bfs 均可用的的情况下建议用 bfs，因为比 dfs 好写，不用控制递归
4.不论哪种一定控制好 isvisit 数组的置位
5.bfs 统计层数可以用数组，也可以把结点设成结构体，里面加上层数
*/
#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int graph[maxn][maxn]={0},n=0,l=0,layer[maxn]={0};
bool isvisit[maxn]={0};
int search(int i)
{
	int forward=0;
	queue<int> q;
	layer[i]=0;
	isvisit[i]=1;
	q.push(i);
	while (!q.empty()) {
		int tt=q.front();
		q.pop();
		for (int h=1;h<=n;h++) {
			if (graph[tt][h]==1&&isvisit[h]==0) {
				layer[h]=layer[tt]+1;
				if (layer[h]<=l) {
					isvisit[h]=1;
					q.push(h);
					forward++;
				}
			}
		}
	}
	return forward;
}
int main()
{
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		for (int j=0;j<k;j++) {
			int tt;
			scanf("%d",&tt);
			graph[tt][i]=1;
		}
	}
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int query;
		scanf("%d",&query);
		memset(isvisit,0,sizeof(isvisit));
		memset(layer,0,sizeof(layer));
		printf("%d\n",search(query));
	}
	return 0;
}
