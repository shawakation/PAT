#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
int main()
{
	ll m,n,domain;
	unordered_map<ll,int> my;
	scanf("%lld%lld",&m,&n);
	ll area=m*n/2;
	for (ll i=0;i<n;i++)
		for (ll j=0;j<m;j++) {
			ll color;
			scanf("%lld",&color);
			my[color]++;
			if (my[color]>area) domain=color;
		}
	printf("%lld",domain);
	return 0;
}
