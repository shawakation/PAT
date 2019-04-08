#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	for (int i=0;i<n-1;i++)
		if (arr[i]>=0&&arr[i+1]-arr[i]>1) {
			printf("%d",arr[i]+1);
			return 0;
		}
	if (arr[n-1]>=0) printf("%d",arr[n-1]+1);
	else printf("1");
	return 0;
}
