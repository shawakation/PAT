#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
bool vis[maxn]={0},output[maxn]={0};
int main()
{
	int n,m;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int k;
		scanf("%d",&k);
		if (k>1) {
			for (int j=0;j<k;j++) {
				int id;
				scanf("%d",&id);
				vis[id]=1;
			}
		}
		else {
			int id;
			scanf("%d",&id);
		}
	}
	scanf("%d",&m);
	vector<int> ans,ans2;
	for (int i=0;i<m;i++) {
		int q;
		scanf("%d",&q);
		if (vis[q]==0) ans.push_back(q);
	}
	if (ans.empty()) printf("No one is handsome\n");
	else {
		for (int i=0;i<ans.size();i++) {
			if (output[ans[i]]==0) {
				ans2.push_back(ans[i]);
				output[ans[i]]=1;
			}
		}
		for (int i=0;i<ans2.size();i++) {
			printf("%05d",ans2[i]);
			if (i<ans2.size()-1) printf(" ");
		}
	}
	return 0;
}
