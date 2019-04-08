#include <bits/stdc++.h>
#define maxn 210
using namespace std;
unordered_set<int> graph[maxn],repeat;
int nv;
void init()
{
	repeat.clear();
	for (int i=1;i<=nv;i++) repeat.insert(i);
}
int main()
{
	int ne,m;
	scanf("%d%d",&nv,&ne);
	for (int i=0;i<ne;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a].insert(b);
		graph[b].insert(a);
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int k;
		scanf("%d",&k);
		vector<int> arr(k);
		for (int j=0;j<k;j++) scanf("%d",&arr[j]);
		bool isnot=0,isnotmax=0;
		init();
		for (int j=0;j<k;j++) {
			if (graph[arr[j]].size()>=k-1) {
				for (int h=0;h<k;h++) {
					if (h!=j&&graph[arr[j]].find(arr[h])==graph[arr[j]].end()) {
						isnot=1;
						break;
					}
				}
				if (isnot) break;
			}
			else {
				isnot=1;
				break;
			}
			repeat.erase(arr[j]);
		}
		if (!isnot) {
			for (auto &p:repeat) if (graph[p].size()>=k) {
				int tt=0;
				for (;tt<k;tt++) if (graph[p].find(arr[tt])==graph[p].end()) break;
				if (tt==k) {
					isnotmax=1;
					break;
				}
			}
		}
		if (isnot) printf("Not a Clique\n");
		else {
			if (isnotmax) printf("Not Maximal\n");
			else printf("Yes\n");
		}
	}
	return 0;
}
