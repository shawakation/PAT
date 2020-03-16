#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	return !b?a:gcd(b,a%b);
}
struct fraction
{
	ll up,down;
	fraction(ll _up,ll _down) {
		up=_up;down=_down;
		reduct();
	}
	void reduct() {
		if (down<0) {
			up=-up;down=-down;
		}
		if (up==0) down=1;
		ll t=gcd(abs(up),abs(down));
		if (t>1) {
			up/=t;down/=t;
		}
	}
	void print() {
		if (down==1) printf("%lld",up);
		else if (up>down) printf("%lld %lld/%lld",up/down,up%down,down);
		else printf("%lld/%lld",up,down);
	}
	fraction operator + (const fraction &a) {
		fraction tt(up*a.down+down*a.up,down*a.down);
		tt.reduct();
		return tt;
	}
};
int main()
{
	int n;
	scanf("%d",&n);
	fraction sum(0,1);
	for (int i=0;i<n;i++) {
		ll up,down;
		scanf("%lld/%lld",&up,&down);
		fraction temp(up,down);
		sum=sum+temp;
	}
	sum.print();
	return 0;
}
