/*
1.这里 leftt rightt 数组分别存储 arr[i] 前面的最大值、最小值
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF=0x7fffffff;
int main()
{
	int n;
	scanf("%d",&n);
	vector<long> ans,arr(n),leftt(n),rightt(n);
	rightt[n-1]=INF;
	for (int i=0; i<n; i++) {
		scanf("%d",&arr[i]);
		if (i>0) leftt[i]=max(arr[i-1],leftt[i-1]);
	}
	for (int i=n-1; i>=0; i--) {
		if (i<n-1) rightt[i]=min(arr[i+1],rightt[i+1]);
		if (leftt[i]<arr[i]&&rightt[i]>arr[i]) ans.push_back(arr[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for (int i=0; i<ans.size(); i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
	return 0;
}
