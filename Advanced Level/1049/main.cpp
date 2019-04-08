/*
1.难题，好好想明白逻辑
*/
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ll sum=0,n,a=1;
	scanf("%lld",&n);
	while (n/a) {
		ll left=n/(a*10);
		ll right=n%a;
		ll now=n/a%10;
		if (now==0) sum+=left*a;
		else if (now==1) sum+=left*a+right+1;
		else if (now>1) sum+=(left+1)*a;
		a*=10;
	}
	printf("%lld",sum);
	return 0;
}
