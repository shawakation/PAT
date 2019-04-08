#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
bool vis[maxn]={0};
int n;
unordered_set<int> graph[maxn];
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		vector<int> arr(n);
		unordered_set<int> my;
		for (int j=0;j<n;j++) scanf("%d",&arr[j]);
		memset(vis,0,sizeof(vis));
		bool isnot=0;
		for (int j=0;j<n;j++) {
			for (auto &p:graph[j])
				if (vis[p]==0&&arr[j]==arr[p]) {
					isnot=1;
					break;
				}
   			if (isnot) break;
   			vis[j]=1;
   			my.insert(arr[j]);
		}
		if (isnot) printf("No\n");
		else printf("%d-coloring\n",my.size());
	}
	return 0;
}
