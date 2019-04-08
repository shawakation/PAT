/*
1.数组预处理思想：边输入边求和
2.认真！注意条件要写全
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m=0,arr[100010]= {0},outt1=-1,outt2=-1;
const int INF=1000000001;
int main()
{
	int n,mint=INF;
	bool flag=1;
	scanf("%d %d",&n,&m);
	for (int i=1; i<=n; i++) {
		int t;
		scanf("%d",&t);
		arr[i]=t+arr[i-1];
	}
	for (int i=0; i<n; i++) {
		int j=m+arr[i];
		int dis=int(lower_bound(arr+i+1,arr+n+1,j)-arr);
		int cha=arr[dis]-arr[i];
		if (dis!=n+1&&cha==m) {
			printf("%d-%d\n",i+1,dis);
			flag=0;
		} else {
			if (flag&&dis!=n+1&&cha<mint) {
				mint=cha;
				outt1=i+1;
				outt2=dis;
			}
		}
	}
	if (flag) {
		printf("%d-%d\n",outt1,outt2);
		for (int i=0; i<n; i++) {
			int j=mint+arr[i];
			int dis=int(lower_bound(arr+i+1,arr+n+1,j)-arr);
			if (dis!=n+1&&arr[dis]-arr[i]==mint&&outt1!=i+1&&outt2!=dis)
				printf("%d-%d\n",i+1,dis);
		}
	}
	return 0;
}
