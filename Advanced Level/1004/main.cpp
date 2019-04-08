#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node {
	int data;
	int layer;
	vector<int> child;
} nodes[120];
int ans[120]= {0},maxlayer=1;
void layerorder(int a)
{
	queue<int> q;
	q.push(a);
	nodes[a].layer=1;
	while (!q.empty()) {
		int e=q.front();
		q.pop();
		if (nodes[e].child.size()==0) ans[nodes[e].layer]++;
		else
			for (int h=0; h<nodes[e].child.size(); h++) {
				nodes[nodes[e].child.at(h)].layer=nodes[e].layer+1;
				if (nodes[e].layer+1>maxlayer) maxlayer=nodes[e].layer+1;
				q.push(nodes[e].child.at(h));
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
		nodes[id].data=id;
		for (int j=0; j<k; j++) {
			int tt;
			scanf("%d",&tt);
			nodes[id].child.push_back(tt);
		}
	}
	layerorder(1);
	for (int i=1;i<=maxlayer;i++) {
		printf("%d",ans[i]);
		if (i<maxlayer) printf(" ");
	}
	printf("\n");
	return 0;
}
