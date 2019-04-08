#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
unordered_set<int> graph[maxn];
vector<pair<int,int> > re;
void backup(int a,int b)
{
	re.push_back(make_pair(a,b));
	graph[a].erase(b);
	graph[b].erase(a);
}
void restore()
{
	while (!re.empty()) {
		pair<int,int> it=re[re.size()-1];
		re.pop_back();
		graph[it.first].insert(it.second);
		graph[it.second].insert(it.first);
	}
}
int main()
{
	int n,m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int t,num=0;
		scanf("%d",&t);
		for (int j=0;j<t;j++) {
			int e;
			scanf("%d",&e);
			while (!graph[e].empty()) {
				backup(e,*(graph[e].begin()));
				num++;
			}
		}
		if (num==m) printf("Yes\n");
		else printf("No\n");
		if (i<k-1) restore();
	}
	return 0;
}
