#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end(),greater<int>());
	int e=0;
	while (arr[e]>e+1&&e<n) e++;
	printf("%d\n",e);
	return 0;
}
