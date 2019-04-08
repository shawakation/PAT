#include <bits/stdc++.h>
#define maxn 210
using namespace std;
short graph[maxn][maxn]={0};
unordered_set<int> vis;
int n,mindis=INT_MAX,ans;
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int c1,c2,w;
		scanf("%d%d%d",&c1,&c2,&w);
		graph[c1][c2]=graph[c2][c1]=w;
	}
	scanf("%d",&k);
	for (int i=1;i<=k;i++) {
		int n2;
		scanf("%d",&n2);
		vector<int> arr(n2);
		for (int j=0;j<n2;j++) scanf("%d",&arr[j]);
		int totaldis=0;
		bool isnot=0,issimple=1,NA=0;
		vis.clear();
		for (int j=1;j<n2;j++) {
			if (graph[arr[j-1]][arr[j]]==0) {
				isnot=1;
				NA=1;
				break;
			}
			if (vis.find(arr[j])!=vis.end()) issimple=0;
			vis.insert(arr[j]);
			totaldis+=graph[arr[j-1]][arr[j]];
		}
		if (vis.size()<n) isnot=1;
		if (!isnot&&totaldis<mindis) {
			mindis=totaldis;
			ans=i;
		}
		if (isnot) {
			if (NA) printf("Path %d: NA (Not a TS cycle)\n",i);
			else printf("Path %d: %d (Not a TS cycle)\n",i,totaldis);
		}
		else {
			if (issimple) printf("Path %d: %d (TS simple cycle)\n",i,totaldis);
			else printf("Path %d: %d (TS cycle)\n",i,totaldis);
		}
	}
	printf("Shortest Dist(%d) = %d\n",ans,mindis);
	return 0;
}
