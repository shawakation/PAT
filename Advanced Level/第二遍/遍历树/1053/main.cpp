#include <bits/stdc++.h>
#define maxn 110
using namespace std;
struct node
{
	int w;
	vector<int> child;
}nodes[maxn];
int weight,n;
vector<int> temp;
vector<vector<int> > ans;
bool cmp(const vector<int> &a,const vector<int> &b)
{
	int len=min(a.size(),b.size());
	for (int i=0;i<len;i++) {
		if (nodes[a[i]].w>nodes[b[i]].w) return 1;
		else if (nodes[a[i]].w<nodes[b[i]].w) return 0;
	}
	return 0;
}
void search(int index,int sum)
{
	temp.push_back(index);
	if (sum==weight&&nodes[index].child.size()==0) {
		ans.push_back(temp);
		temp.pop_back();
		return;
	}
	if (sum>weight) {
		temp.pop_back();
		return;
	}
	for (int h=0;h<nodes[index].child.size();h++)
		search(nodes[index].child[h],sum+nodes[nodes[index].child[h]].w);
	temp.pop_back();
}
int main()
{
	int m;
	scanf("%d%d%d",&n,&m,&weight);
	for (int i=0;i<n;i++) scanf("%d",&nodes[i].w);
	for (int i=0;i<m;i++) {
		int id,k;
		scanf("%d%d",&id,&k);
		for (int j=0;j<k;j++) {
			int c;
			scanf("%d",&c);
			nodes[id].child.push_back(c);
		}
	}
	search(0,nodes[0].w);
	sort(ans.begin(),ans.end(),cmp);
	for (int i=0;i<ans.size();i++) {
		for (int j=0;j<ans[i].size();j++) {
			printf("%d",nodes[ans[i][j]].w);
			if (j<ans[i].size()-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
