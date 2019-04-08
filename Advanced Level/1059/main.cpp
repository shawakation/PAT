/*
1.不一定要打素数表，直接判断 2 到 sqrt(n) 也可以
2.用 map 输出时控制最后不输出某个字符的方法：设置计数变量
*/
#include <iostream>
#include <map>
#include <cmath>
using namespace std;
bool isprime(long n)
{
	if (n<2) return 0;
	long sqr=(long)sqrt(n);
	for (int i=2; i<=sqr; i++) if (n%i==0) return 0;
	return 1;
}
int main()
{
	long n;
	int countt=0;
	map<long,int> my;
	scanf("%ld",&n);
	if (n==1) {
		printf("1=1");
		return 0;
	}
	long temp=n;
	long sqr=(long)sqrt(n);
	for (long i=2; i<=sqr; i++) {
		if (isprime(i))
			while (n%i==0) {
				my[i]++;
				n/=i;
			}
	}
	if (n>1) my[n]++;
	printf("%ld=",temp);
	for (auto p=my.begin(); p!=my.end(); p++) {
		if (p->second>1) printf("%ld^%d",p->first,p->second);
		else if (p->second==1) printf("%ld",p->first);
		countt++;
		if (countt<my.size()) printf("*");
	}
	return 0;
}
