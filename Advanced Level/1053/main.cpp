/*
1.本题用DFS，注意节点入栈和出栈的情况
2.对于本题输出的要求，可以写一个对 vector<int> 排序的函数，作用在 vector<vector<int>>上
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define maxn 120
using namespace std;
struct node {
	int weight;
	vector<int> child;
} nodes[maxn];
int s;
vector<vector<int> > ans;
vector<int> res;
bool cmp(vector<int> &a,vector<int> &b)
{
	int mint=min(a.size(),b.size());
	for (int g=0; g<mint; g++)
		if (nodes[a[g]].weight>nodes[b[g]].weight) return 1;
		else if (nodes[a[g]].weight<nodes[b[g]].weight) return 0;
	return 0;
}
void search(int r,int sum)
{
	res.push_back(r);
	if (nodes[r].child.size()==0) {
		if (sum==s) ans.push_back(res);
		res.pop_back();
		return;
	}
	for (int l=0; l<nodes[r].child.size(); l++)
		search(nodes[r].child[l],sum+nodes[nodes[r].child[l]].weight);
	res.pop_back();
}
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&s);
	for (int i=0; i<n; i++) scanf("%d",&nodes[i].weight);
	for (int i=0; i<m; i++) {
		int id,k;
		scanf("%d%d",&id,&k);
		for (int j=0; j<k; j++) {
			int tt;
			scanf("%d",&tt);
			nodes[id].child.push_back(tt);
		}
	}
	search(0,nodes[0].weight);
	sort(ans.begin(),ans.end(),cmp);
	for (int i=0; i<ans.size(); i++) {
		for (int j=0; j<ans[i].size(); j++) {
			printf("%d",nodes[ans[i][j]].weight);
			if (j<ans[i].size()-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
