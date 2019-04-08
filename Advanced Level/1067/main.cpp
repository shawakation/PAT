/*
1.algorithm里面的 find 与 is_sorted 函数会耗费大量时间
2.使用 right 表示未正确归位的数字（除了0之外）
3.定义全局变量 k 使找交换位置时时间为线性增长
*/
#include <iostream>
#include <algorithm>
#define maxn 100010
using namespace std;
int arr[maxn]={0};
int main()
{
	int n,sum=0,k=1,right;
	scanf("%d",&n);
	right=n-1;
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		if (arr[i]==i) right--;
	}
  	while (right>0) {
  		if (arr[0]==0) {
  			while (k<n&&arr[k]==k) k++;
  			swap(arr[k],arr[0]);
  			sum++;
		}
		while (arr[0]!=0) {
			swap(arr[0],arr[arr[0]]);
			sum++;
			right--;
		}
	}
	printf("%d\n",sum);
	return 0;
}
