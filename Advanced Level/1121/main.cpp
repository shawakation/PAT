#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
bool vis[maxn]={0};
unordered_map<int,int> my;
set<int> ans;
int main()
{
	int n,m;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		my[a]=b;
		my[b]=a;
	}
	scanf("%d",&m);
	vector<int> arr(m);
	for (int i=0;i<m;i++) scanf("%d",&arr[i]);
	for (int i=0;i<m;i++) {
		if (vis[arr[i]]==0) {
			auto it=my.find(arr[i]);
			if (it==my.end()) ans.insert(arr[i]);
			else {
				bool flag=1;
				int t=it->second;
				for (int j=i+1;j<m;j++) if (vis[arr[j]]==0&&arr[j]==t) {
					flag=0;
					vis[arr[j]]=1;
					break;
				}
				if (flag) ans.insert(arr[i]);
			}
			vis[arr[i]]=1;
		}
	}
	int countt=ans.size();
	printf("%d\n",countt);
	for (auto &p:ans) {
		printf("%05d",p);
		countt--;
		if (countt>0) printf(" ");
	}
	return 0;
}
