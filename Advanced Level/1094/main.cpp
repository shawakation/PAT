#include <iostream>
#include <vector>
#include <queue>
#define maxn 120
using namespace std;
struct node {
	int layer;
	vector<int> child;
} nodes[maxn];
int gercount[maxn]= {0};
void layerorder(int r)
{
	queue<int> q;
	nodes[r].layer=1;
	q.push(r);
	while (!q.empty()) {
		int pp=q.front();
		q.pop();
		gercount[nodes[pp].layer]++;
		if (nodes[pp].child.size()>0) {
			for (int h=0; h<nodes[pp].child.size(); h++) {
				nodes[nodes[pp].child[h]].layer=nodes[pp].layer+1;
				q.push(nodes[pp].child[h]);
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0; i<m; i++) {
		int id,k;
		scanf("%d%d",&id,&k);
		for (int j=0; j<k; j++) {
			int t;
			scanf("%d",&t);
			nodes[id].child.push_back(t);
		}
	}
	layerorder(1);
	int maxcountt=0,maxlayer=1;
	for (int i=1; i<=n; i++)
		if (gercount[i]>maxcountt) {
			maxcountt=gercount[i];
			maxlayer=i;
		}
	printf("%d %d\n",maxcountt,maxlayer);
	return 0;
}
