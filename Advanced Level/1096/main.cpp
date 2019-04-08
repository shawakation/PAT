/*
1.最后一个测试点的因子是 1 和 本身，可以猜样例
2.注意：n 只能被除本身之外的小于 sqrt(n) 的整数整除
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long n,startnum=0;
	int maxlens=0;
	scanf("%ld",&n);
	long sqr=(long)sqrt(n*1.0);
	for (long i=2; i<=sqr; i++) {
		long a=i,e=1;
		int countt=0;
		while (n%a==0) {
			a*=i+(e++);
			countt++;
		}
		if (countt>maxlens) {
			maxlens=countt;
			startnum=i;
		}
	}
	if (maxlens==0) printf("1\n%ld",n);
	else {
		printf("%d\n",maxlens);
		for (int i=0; i<maxlens; i++) {
			printf("%ld",startnum+i);
			if (i<maxlens-1) printf("*");
		}
	}
	printf("\n");
	return 0;
}
