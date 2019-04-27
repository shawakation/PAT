#include <cstdio>
#include <queue>
#include <unordered_set>
#include <memory.h>
#define maxn 10010
using namespace std;
bool vis[maxn];
int layer[maxn];
unordered_set<int> graph[maxn];
int search(int s)
{
	queue<int> q;
	int nodenum=0;
	vis[s]=1;
	layer[s]=1;
	q.push(s);
	while (!q.empty()) {
		int p=q.front();
		q.pop();
		nodenum++;
		for (int k:graph[p]) {
			if (vis[k]==0) {
				layer[k]=layer[p]+1;
				if (layer[k]<=7) {
					q.push(k);
					vis[k]=1;
				}
			}
		}
	}
	return nodenum;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	for (int i=1;i<=n;i++) {
		memset(vis,0,sizeof(vis));
		memset(layer,0,sizeof(layer));
		int num=search(i);
		printf("%d: %.2f%%\n",i,(double)num/(double)n*100.0f);
	}
	return 0;
}
