/*
1.逻辑题，找到规律很好解
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	double sum=0.0;
	scanf("%d",&n);
	vector<double> arr(n);
	for (int i=0;i<n;i++) scanf("%lf",&arr[i]);
	for (int i=0;i<n;i++) sum+=arr[i]*(n-i)*(i+1);
	printf("%.2lf",sum);
	return 0;
}
