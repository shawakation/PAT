#include <bits/stdc++.h>
#define maxn 210
using namespace std;
int graph[maxn][maxn]={0};
int main()
{
	int n,m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		graph[a][b]=graph[b][a]=c;
	}
	int shortest=INT_MAX,id=0;
	scanf("%d",&k);
	for (int i=1;i<=k;i++) {
		int t;
		scanf("%d",&t);
		vector<int> arr(t);
		for (int j=0;j<t;j++) scanf("%d",&arr[j]);
		int dis=0;
		bool iscycle=1,na=0,issimple=1;
		unordered_set<int> re;
		for (int j=1;j<t;j++) {
			if (graph[arr[j-1]][arr[j]]==0) {
				iscycle=0;
				na=1;
				break;
			}
			re.insert(arr[j]);
			if (arr[j]==arr[0]&&j<t-1) issimple=0;
			dis+=graph[arr[j-1]][arr[j]];
		}
		if (re.size()<n) iscycle=0;
		if (arr[t-1]!=arr[0]) iscycle=0;
		if (iscycle) {
			if (issimple) printf("Path %d: %d (TS simple cycle)\n",i,dis);
			else printf("Path %d: %d (TS cycle)\n",i,dis);
			if (shortest>dis) {
				shortest=dis;
				id=i;
			}
		}
		else {
			if (na) printf("Path %d: NA (Not a TS cycle)\n",i);
			else printf("Path %d: %d (Not a TS cycle)\n",i,dis);
		}
	}
	printf("Shortest Dist(%d) = %d\n",id,shortest);
	return 0;
}
