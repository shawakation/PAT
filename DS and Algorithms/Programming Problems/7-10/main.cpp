#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int father[maxn];
void init(int n)
{
	for (int i=1;i<=n;i++) father[i]=i;
}
int find(int x)
{
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
struct edge
{
	int u,v,cost;
	edge(int _u,int _v,int _c) {
		u=_u;v=_v;cost=_c;
	}
	friend bool operator < (const edge &a,const edge &b) {
		return a.cost<b.cost;
	}
};
multiset<edge> edges;
int calc(int n)
{
	int edgenum=0,weight=0;
	for (auto &p:edges) {
		int aa=find(p.u),bb=find(p.v);
		if (aa!=bb) {
			father[aa]=bb;
			weight+=p.cost;
			edgenum++;
			if (edgenum==n-1) break;
		}
	}
	if (edgenum==n-1) return weight;
	else return -1;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edges.insert(edge(a,b,c));
	}
	printf("%d",calc(n));
	return 0;
}
