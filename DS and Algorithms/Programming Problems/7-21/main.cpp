#include <bits/stdc++.h>
#define maxn 110
using namespace std;
int countt[maxn]={0},layer[maxn]={0},maxlayer=0;
vector<int> nodes[maxn];
void init()
{
	for (int i=0;i<maxn;i++) nodes[i].clear();
	memset(countt,0,sizeof(countt));
	memset(layer,0,sizeof(layer));
	maxlayer=0;
}
void layerorder(int root)
{
	queue<int> q;
	layer[root]=1;
	q.push(root);
	while (!q.empty()) {
		int tt=q.front();
		q.pop();
		if (nodes[tt].size()==0) {
			countt[layer[tt]]++;
			maxlayer=max(maxlayer,layer[tt]);
		}
		else for (int h=0;h<nodes[tt].size();h++) {
			layer[nodes[tt][h]]=layer[tt]+1;
			q.push(nodes[tt][h]);
		}
	}
}
int main()
{
	int n,m;
	while (1) {
		scanf("%d%d",&n,&m);
		if (n==0) break;
		init();
		for (int i=0;i<m;i++) {
			int nonleaf,k;
			scanf("%d%d",&nonleaf,&k);
			for (int j=0;j<k;j++) {
				int id;
				scanf("%d",&id);
				nodes[nonleaf].push_back(id);
			}
		}
		layerorder(1);
		for (int i=1;i<=maxlayer;i++) {
			printf("%d",countt[i]);
			if (i<maxlayer) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
