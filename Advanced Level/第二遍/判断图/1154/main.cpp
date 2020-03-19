#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
unordered_set<int> graph[maxn];
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
		vector<int> arr(n);
		unordered_set<int> repeat;
		for (int j=0;j<n;j++) {
			scanf("%d",&arr[j]);
			repeat.insert(arr[j]);
		}
		bool flag=0;
		for (int j=0;j<n;j++) {
			for (auto &p:graph[j]) {
				if (arr[j]==arr[p]) {
					flag=1;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) printf("No\n");
		else printf("%d-coloring\n",repeat.size());
	}
	return 0;
}
