#include <iostream>
#include <vector>
#include <queue>
#define maxn 100010
using namespace std;
struct node {
	vector<int> child;
	double price;
	double product;
} nodes[maxn];
double totalsal=0,p,r;
void layerorder(int e)
{
	queue<int> q;
	nodes[e].price=p;
	q.push(e);
	while (!q.empty()) {
		int ww=q.front();
		q.pop();
		if (nodes[ww].child.size()==0) totalsal+=nodes[ww].price*nodes[ww].product;
		else {
			for (int h=0; h<nodes[ww].child.size(); h++) {
				nodes[nodes[ww].child[h]].price=nodes[ww].price*(1+r/100.0);
				q.push(nodes[ww].child[h]);
			}
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
		if (k==0) scanf("%lf",&nodes[i].product);
		else
			for (int j=0; j<k; j++) {
				int t;
				scanf("%d",&t);
				nodes[i].child.push_back(t);
			}
	}
	layerorder(0);
	printf("%.1lf\n",totalsal);
	return 0;
}
