/*
1.应用数组，用数组的下标表示某些东西！
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector<double> arr(1001);
	int n1,n2;
	scanf("%d",&n1);
	for (int i=0;i<n1;i++) {
		int exp;
		double coe;
		scanf("%d%lf",&exp,&coe);
		arr[exp]+=coe;
	}
	scanf("%d",&n2);
	for (int i=0;i<n2;i++) {
		int exp;
		double coe;
		scanf("%d%lf",&exp,&coe);
		arr[exp]+=coe;
	}
	int num=0;
	for (int i=0;i<1001;i++) {
		if (arr[i]!=0) num++;
	}
	if (num) printf("%d ",num);
	else {
		printf("%d",num);
		return 0;
	}
	for (int i=1000;i>=0;i--) {
		if (arr[i]!=0) {
			printf("%d %.1lf",i,arr[i]);
			num--;
			if (num) printf(" ");
		}
	}
	return 0;
}
