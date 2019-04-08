/*
1.A1079的翻版，套路一样
*/
#include <iostream>
#include <vector>
#include <queue>
#define maxn 100010
using namespace std;
struct node {
	double price;
	int layer;
	vector<int> child;
} nodes[maxn];
double p,r,maxprice=0.0;
int maxlayer=1;
void layerorder(int k)
{
	queue<int> q;
	nodes[k].layer=1;
	nodes[k].price=p;
	maxprice=p;
	q.push(k);
	while (!q.empty()) {
		int tt=q.front();
		q.pop();
		if (nodes[tt].child.size()!=0) {
			for (int h=0; h<nodes[tt].child.size(); h++) {
				nodes[nodes[tt].child[h]].layer=nodes[tt].layer+1;
				nodes[nodes[tt].child[h]].price=nodes[tt].price*(1+r/100.0);
				if (nodes[nodes[tt].child[h]].layer>maxlayer)
					maxlayer=nodes[nodes[tt].child[h]].layer;
				if (nodes[nodes[tt].child[h]].price>maxprice)
					maxprice=nodes[nodes[tt].child[h]].price;
				q.push(nodes[tt].child[h]);
			}
		}
	}
}
int main()
{
	int n,root,countt=0;
	scanf("%d%lf%lf",&n,&p,&r);
	for (int i=0; i<n; i++) {
		int t;
		scanf("%d",&t);
		if (t!=-1) nodes[t].child.push_back(i);
		else root=i;
	}
	layerorder(root);
	for (int i=0;i<n;i++) if (nodes[i].layer==maxlayer) countt++;
	printf("%.2f %d\n",maxprice,countt);
	return 0;
}
