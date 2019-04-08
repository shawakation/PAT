#include <bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int> nodes[maxn];
struct node
{
	int id,deep;
	node(int a,int b) {
		id=a;deep=b;
	}
};
bool cmp(node a,node b)
{
	if (a.deep!=b.deep) return a.deep>b.deep;
	else return a.id<b.id;
}
vector<node> ans;
int layer[maxn]={0};
bool isinq[maxn]={0};
int search(int k)
{
	int maxlayer=-1;
	queue<int> q;
	isinq[k]=1;
	layer[k]=1;
	q.push(k);
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		if (layer[t]>maxlayer) maxlayer=layer[t];
		for (int h=0;h<nodes[t].size();h++) {
			int tt=nodes[t][h];
			if (isinq[tt]==0) {
				isinq[tt]=1;
				layer[tt]=layer[t]+1;
				q.push(tt);
			}
		}
	}
	return maxlayer;
}
void qingling()
{
	memset(layer,0,sizeof(layer));
	memset(isinq,0,sizeof(isinq));
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		nodes[a].push_back(b);
		nodes[b].push_back(a);
	}
	int countt=0;
	for (int i=1;i<=n;i++)
		if (isinq[i]==0) {
			search(i);
			countt++;
		}
	if (countt==1) {
		int maxdeep=0;
		for (int i=1;i<=n;i++) {
			qingling();
			int qq=search(i);
			ans.push_back(node(i,qq));
		}
		sort(ans.begin(),ans.end(),cmp);
		maxdeep=ans[0].deep;
		for (int j=0;j<ans.size()&&ans[j].deep==maxdeep;j++) printf("%d\n",ans[j].id);
	}
	else printf("Error: %d components\n",countt);
	return 0;
}
