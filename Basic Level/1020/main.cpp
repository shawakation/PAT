/*
1.贪心的思想：先把月饼按单价从大到小排，再从首位开始计算直到满足需求
2.printf的标志控制位：%04d %.2f %.2lf %-d % d
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct mooncake
{
	float mount;
	float price;
	float unitprice;
};
bool cmp(struct mooncake a,struct mooncake b)
{
	return a.unitprice>b.unitprice;
}
int main()
{
	int n,need;
	cin>>n>>need;
	vector<mooncake> arr(n);
	for (int i=0;i<n;i++) cin>>arr[i].mount;
	for (int i=0;i<n;i++) {
		cin>>arr[i].price;
		arr[i].unitprice=arr[i].price/arr[i].mount;
	}
	sort(arr.begin(),arr.end(),cmp);
	float sum=0.0f;
	for (int i=0;i<n;i++) {
		if (arr[i].mount<=need) {
			sum+=arr[i].price;
			need-=arr[i].mount;
		}
		else {
			sum+=need*arr[i].unitprice;
			break;
		}
	}
	printf("%.2f",sum);
	return 0;
}
