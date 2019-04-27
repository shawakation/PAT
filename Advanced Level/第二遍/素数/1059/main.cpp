#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime(ll n)
{
	if (n<2) return 0;
	ll sqr=(ll)sqrt(n);
	for (ll i=2;i<=sqr;i++) if (n%i==0) return 0;
	return 1;
}
map<ll,int> my;
int main()
{
	ll n,t;
	scanf("%lld",&n);
	if (n==1) {
		printf("1=1");
		return 0;
	}
	t=n;
	ll i=2;
	while (n>1) {
		while (!isprime(i)) i++;
		while (n%i==0&&n>1) {
			my[i]++;
			n/=i;
		}
		i++;
	}
	printf("%lld=",t);
	int s=my.size();
	for (auto &p:my) {
		if (p.second>1) printf("%lld^%d",p.first,p.second);
		else printf("%lld",p.first);
		s--;
		if (s>0) printf("*");
	}
	return 0;
}
