/*
1.二分查找的思想，枚举每个 i，二分查找最大的 j，注意这里的逻辑
    用找第一个大于等于的 upper_bound，需要从右往左找
    要用到 rbegin() rend()
2.初值设为 1，表示至少有一个数
3.反向迭代器不能和正向迭代器相加减
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	long p;
	scanf("%d%ld",&n,&p);
	vector<long> arr(n);
	for (int i=0;i<n;i++) scanf("%ld",&arr[i]);
	sort(arr.begin(),arr.end());
	int ans=1;
	for (int i=0;i<n-1;i++) {
		int j=(int)(lower_bound(arr.rbegin(),arr.rend(),(long long)arr[i]*p,greater<long long>())-arr.rbegin());
		ans=max(ans,n-j-i);
	}
	printf("%d",ans);
	return 0;
}
