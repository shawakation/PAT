/*
可以化简，用更简单的方法
*/
#include <iostream>
#include <algorithm>
using namespace std;
int huifu(int qian,int bai,int shi,int ge)
{
	return qian*1000+bai*100+shi*10+ge;
}
bool dijianpai(int a,int b)
{
	return a>b;
}
void zhuanhua(int num,int &qian,int &bai,int &shi,int &ge)
{
	ge=num%10;
	num/=10;
	shi=num%10;
	num/=10;
	bai=num%10;
	num/=10;
	qian=num;
}
int main()
{
	int n;
	cin>>n;
	if (n==6174) {
		printf("7641 - 1467 = 6174\n");
		return 0;
	}
	while (n!=6174) {
		int arr[4];
		zhuanhua(n,arr[0],arr[1],arr[2],arr[3]);
		sort(arr,arr+4);
		int dizeng=huifu(arr[0],arr[1],arr[2],arr[3]);
		sort(arr,arr+4,dijianpai);
		int dijian=huifu(arr[0],arr[1],arr[2],arr[3]);
		if (dizeng==dijian) {
			printf("%04d - %04d = %04d\n",dizeng,dijian,0);
			return 0;
		}
		else {
			n=dijian-dizeng;
			printf("%04d - %04d = %04d\n",dijian,dizeng,n);
		}
	}
	return 0;
}
