#include <bits/stdc++.h>
#define maxn 210
using namespace std;
int graph[maxn][maxn]={0};
int main()
{
	int n,m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int t;
		scanf("%d",&t);
		vector<int> arr(t);
		unordered_set<int> my;
		for (int j=0;j<t;j++) {
			scanf("%d",&arr[j]);
			my.insert(arr[j]);
		}
		bool isnot=0,isnotmax=0;
		for (int j=0;j<t;j++) {
			for (int h=j+1;h<t;h++) {
				if (graph[arr[j]][arr[h]]==0) {
					isnot=1;
					break;
				}
			}
			if (isnot) break;
		}
		if (isnot) printf("Not a Clique\n");
		else {
			for (int j=1;j<=n;j++) {
				if (my.find(j)==my.end()) {
					bool flag=1;
					for (int h=0;h<t;h++) if (graph[j][arr[h]]==0) {
						flag=0;
						break;
					}
					if (flag) {
						isnotmax=1;
						break;
					}
				}
			}
			if (isnotmax) printf("Not Maximal\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
