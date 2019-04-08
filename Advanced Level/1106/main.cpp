#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define maxn 100010
using namespace std;
struct node {
	int layer;
	vector<int> child;
} nodes[maxn];
double p,r;
int lowlayer=maxn;
vector<int> leaf;
void layerorder(int r1)
{
	queue<int> q;
	nodes[r1].layer=0;
	q.push(r1);
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		if (nodes[t].child.size()==0) {
			if (nodes[t].layer<lowlayer) lowlayer=nodes[t].layer;
			leaf.push_back(t);
		} else if (nodes[t].child.size()>0)
			for (int h=0; h<nodes[t].child.size(); h++) {
				nodes[nodes[t].child[h]].layer=nodes[t].layer+1;
				q.push(nodes[t].child[h]);
			}
	}
}
int main()
{
	int n;
	scanf("%d%lf%lf",&n,&p,&r);
	for (int i=0; i<n; i++) {
		int k;
		scanf("%d",&k);
		for (int j=0; j<k; j++) {
			int tt;
			scanf("%d",&tt);
			nodes[i].child.push_back(tt);
		}
	}
	layerorder(0);
	int countt=0;
	for (int i=0; i<leaf.size(); i++)
		if (nodes[leaf[i]].layer==lowlayer) countt++;
	double lowprice=p*pow(1+r/100,lowlayer);
	printf("%.4lf %d\n",lowprice,countt);
	return 0;
}
