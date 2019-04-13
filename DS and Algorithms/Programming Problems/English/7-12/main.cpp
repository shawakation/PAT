/*
1.关键路径注意：最后输出 ve 数组中最大的元素，不一定是 ve[n-1]
*/
#include <bits/stdc++.h>
#define maxn 110
using namespace std;
int ve[maxn]={0},n,indegree[maxn]={0};
struct node
{
	int next,w;
	node(int _next,int _w) {
		next=_next;w=_w;
	}
};
vector<node> graph[maxn];
bool topo()
{
	queue<int> q;
	int nodenum=0;
	for (int i=0;i<n;i++) if (indegree[i]==0) q.push(i);
	while (!q.empty()) {
		int tt=q.front();
		q.pop();
		nodenum++;
		for (auto &p:graph[tt]) {
			indegree[p.next]--;
			if (indegree[p.next]==0) q.push(p.next);
			if (ve[p.next]<ve[tt]+p.w) ve[p.next]=ve[tt]+p.w;
		}
		graph[tt].clear();
	}
	if (nodenum==n) return 1;
	else return 0;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a].push_back(node(b,c));
		indegree[b]++;
	}
	if (topo()) printf("%d",*max_element(ve,ve+n));
	else printf("Impossible");
	return 0;
}
