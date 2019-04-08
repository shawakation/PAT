/*
1.按单价从大到小排，实现贪心
2.注意库存数量可能是小数，因为题目中没有说，最好用double
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct mooncake
{
	double tprice,sprice,amount;
};
bool cmp(mooncake a,mooncake b)
{
	return a.sprice>b.sprice;
}
int main()
{
	int n;
	double m;
	scanf("%d%lf",&n,&m);
	vector<mooncake> arr(n);
	for (int i=0;i<n;i++) scanf("%lf",&arr[i].amount);
	for (int i=0;i<n;i++) {
		scanf("%lf",&arr[i].tprice);
		arr[i].sprice=arr[i].tprice/arr[i].amount;
	}
	sort(arr.begin(),arr.end(),cmp);
	double profit=0.0;
	for (int i=0;i<n;i++) {
		if (arr[i].amount<=m) {
			profit+=arr[i].tprice;
			m-=arr[i].amount;
		}
		else {
			profit+=m*arr[i].sprice;
			break;
		}
	}
	printf("%.2lf",profit);
	return 0;
}
