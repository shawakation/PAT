/*
1.这道题可以说是贪心中很难的了，好好体会思路
2.题目中没有说是正整数，并且从实际意义考虑可以是小数的变量最好用 double 存
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;
struct station
{
	double price,dis;
};
bool cmp(station a,station b)
{
	if (a.dis!=b.dis) return a.dis<b.dis;
	else return a.price<b.price;
}
int main()
{
	double Cmax,D,Davg;
	int n;
	scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&n);
	vector<station> arr(n+1);
	for (int i=0;i<n;i++)
		scanf("%lf %lf",&arr[i].price,&arr[i].dis);
	arr[n].price=0.0;
	arr[n].dis=D;
	sort(arr.begin(),arr.end(),cmp);
	if (arr[0].dis>0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int cur=0;
	double totalexp=0.0,maxdis=Cmax*Davg,curCap=0.0;
	while (cur<n) {
		/*
        找下一个加油站（从当前加油站开始，且要在行驶的范围内）
        思想：如果有比当前油价更低的就直接选定其
                如果没有就选择一个油价最低的
                如果找不到说明不能到下一个了，直接输出
		*/
		int k=0;
		double minPrice=INF;
		for (int i=cur+1;i<=n&&arr[i].dis-arr[cur].dis<=maxdis;i++) {
			if (arr[i].price<minPrice) {
				minPrice=arr[i].price;
				k=i;
			}
			if (minPrice<arr[cur].price) break;
		}
		if (k==0) {
			double overDis=arr[cur].dis+maxdis;
			printf("The maximum travel distance = %.2lf\n",overDis);
			return 0;
		}
		/*
        从当前到下一个加油站，思路：
        1.如果下个加油站油价小于当前，则只加能够到下个加油站的油，到下个后油量为0
        2.如果不是，则在当前把油加满，并到下一个，油量减去相应的
        3.计算费用
		*/
		double need=(arr[k].dis-arr[cur].dis)/Davg;
		if (minPrice<arr[cur].price)
			if (curCap<need) {
				totalexp+=(need-curCap)*arr[cur].price;
				curCap=0;
			}
			else curCap-=need;
		else {
			totalexp+=(Cmax-curCap)*arr[cur].price;
			curCap=Cmax;
			curCap-=need;
		}
		cur=k;
	}
	printf("%.2lf\n",totalexp);
	return 0;
}
