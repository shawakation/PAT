#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	unordered_map<int,vector<int> > my;
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		my[a].push_back(b);
		my[b].push_back(a);
	}
	for (int i=0;i<m;i++) {
		int k;
		bool flag=1;
		scanf("%d",&k);
		vector<int> arr(k);
		for (int j=0;j<k;j++) scanf("%d",&arr[j]);
		for (int j=0;j<k;j++) {
			auto it=my.find(arr[j]);
			if (it!=my.end()) {
				vector<int> temp(it->second);
				for (auto &p:temp) {
					for (int t=j+1;t<k;t++) if (p==arr[t]) {
						flag=0;
						break;
					}
					if (!flag) break;
				}
			}
			if (!flag) break;
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
