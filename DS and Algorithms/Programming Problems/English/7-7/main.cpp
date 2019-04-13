#include <bits/stdc++.h>
using namespace std;
vector<int> tree,ans,arr;
int n,index=0;
void inorder(int k)
{
	if (k>n) return;
	inorder(k*2);
	tree[k]=arr[index++];
	inorder(k*2+1);
}
void layerorder(int k)
{
	queue<int> q;
	q.push(k);
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		ans.push_back(tree[t]);
		if (t*2<=n) q.push(t*2);
		if (t*2+1<=n) q.push(t*2+1);
	}
}
int main()
{
	scanf("%d",&n);
	tree.resize(n+1);
	arr.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	inorder(1);
	layerorder(1);
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	return 0;
}
