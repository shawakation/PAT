/*
1.求解n皇后关键：找准同一对角线上的判断条件，同时不能忽视同行同列
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
	int k;
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int n;
		bool flag=0;
		scanf("%d",&n);
		vector<int> arr(n);
		for (int j=0;j<n;j++) scanf("%d",&arr[j]);
		for (int j=1;j<n;j++) {
			for (int g=0;g<j;g++)
				if (arr[j]==arr[g]||abs(j-g)==abs(arr[j]-arr[g])) {
					printf("NO\n");
					flag=1;
					break;
				}
			if (flag) break;
		}
		if (!flag) printf("YES\n");
	}
	return 0;
}
