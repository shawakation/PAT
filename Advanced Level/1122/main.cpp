/*
A1150 µÄ¼òµ¥°æ¡£¡£
*/
#include <bits/stdc++.h>
#define maxn 210
using namespace std;
short graph[maxn][maxn]={0};
bool vis[maxn]={0};
int n;
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int n1;
		bool isnot=0;
		unordered_set<int> my;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n1);
		vector<int> arr(n1);
		for (int j=0;j<n1;j++) scanf("%d",&arr[j]);
		for (int j=1;j<n1;j++) {
			if (graph[arr[j-1]][arr[j]]==0||vis[arr[j]]) {
				isnot=1;
				break;
			}
			my.insert(arr[j]);
			vis[arr[j]]=1;
		}
		if (my.size()<n) isnot=1;
		if (isnot) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
