#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<long> arr(n);
	for (int i=0;i<n;i++) scanf("%ld",&arr[i]);
	sort(arr.begin(),arr.end());
	int left=n/2-1;
	int right=left+1;
	long sumL=0,sumR=0;
	for (int i=0;i<=left;i++) sumL+=arr[i];
	for (int i=right;i<n;i++) sumR+=arr[i];
	printf("%d %ld",n-right*2,sumR-sumL);
	return 0;
}
