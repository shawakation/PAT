/*
1.超时问题：要擦除边，用 unordered_set 实现图的邻接表速度会快好多
2.备份问题：用一个数组，每次完之后进行还原，比备份整个图要快
*/
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
unordered_set<int> my[maxn];
vector<pair<int,int> > restores;
int n;
void restore()
{
	while (!restores.empty()) {
		pair<int,int> temp=restores[restores.size()-1];
		restores.pop_back();
		my[temp.first].insert(temp.second);
		my[temp.second].insert(temp.first);
	}
}
void backup(int a,int b)
{
	restores.push_back(make_pair(a,b));
}
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		my[a].insert(b);
		my[b].insert(a);
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int n1,edges=0;
		scanf("%d",&n1);
		vector<int> arr(n1);
		for (int j=0;j<n1;j++) scanf("%d",&arr[j]);
		for (int j=0;j<n1;j++) {
			while (!my[arr[j]].empty()) {
				int tt=*my[arr[j]].begin();
				my[arr[j]].erase(tt);
				my[tt].erase(arr[j]);
				backup(arr[j],tt);
				edges++;
			}
		}
		if (edges<m) printf("No\n");
		else printf("Yes\n");
		restore();
	}
	return 0;
}
