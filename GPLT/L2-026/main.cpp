#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
vector<int> child[maxn],ans;
int n,maxlayer=0,layer[maxn]={0};
void layerorder(int root)
{
	queue<int> q;
	layer[root]=1;
	q.push(root);
	while (!q.empty()) {
		int tt=q.front();
		q.pop();
		if (layer[tt]>maxlayer) {
			maxlayer=layer[tt];
			ans.clear();
			ans.push_back(tt);
		}
		else if (layer[tt]==maxlayer) ans.push_back(tt);
		for (int h=0;h<child[tt].size();h++) {
			layer[child[tt][h]]=layer[tt]+1;
			q.push(child[tt][h]);
		}
	}
}
int main()
{
	scanf("%d",&n);
	int root;
	for (int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		if (t==-1) root=i;
		else child[t].push_back(i);
	}
	layerorder(root);
	sort(ans.begin(),ans.end());
	printf("%d\n",maxlayer);
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	return 0;
}
