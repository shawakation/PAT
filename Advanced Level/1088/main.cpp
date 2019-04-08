/*
1.问题点：原来是 abs(up)%down==0 printf(up/down)
            不知道哪错了。。。
*/
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	return !b?a:gcd(b,a%b);
}
struct frac {
	public:
		ll up,down;
		frac() {
			up=0;
			down=1;
		}
		frac(ll a,ll b) {
			up=a;
			down=b;
		}
		void reduction() {
			if (up==0) down=1;
			if (down<0) {
				up=-up;
				down=-down;
			}
			ll d=gcd(abs(up),abs(down));
			up/=d;
			down/=d;
		}
		void print() {
			reduction();
			if (up<0) printf("(");
			if (up==0) printf("0");
			else if (abs(up)>=down)
				if (down==1) printf("%lld",up);     //这里有点问题，改成 先化简，down==1就对了
				else printf("%lld %lld/%lld",up/down,abs(up)%down,down);
			else printf("%lld/%lld",up,down);
			if (up<0) printf(")");
		}
		frac operator + (frac &t) {
			frac temp(up*t.down+down*t.up,down*t.down);
			temp.reduction();
			return temp;
		}
		frac operator - (frac &t) {
			frac temp(up*t.down-down*t.up,down*t.down);
			temp.reduction();
			return temp;
		}
		frac operator * (frac &t) {
			frac temp(up*t.up,down*t.down);
			temp.reduction();
			return temp;
		}
		frac operator / (frac &t) {
			frac temp(up*t.down,down*t.up);
			temp.reduction();
			return temp;
		}
};
int main()
{
	ll a1,b1,a2,b2;
	bool flag=0;
	scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
	frac a(a1,b1),b(a2,b2);
	frac c1=a+b,c2=a-b,c3=a*b,c4;
	if (a2) c4=a/b;
	a.print();
	printf(" + ");
	b.print();
	printf(" = ");
	c1.print();
	printf("\n");
	a.print();
	printf(" - ");
	b.print();
	printf(" = ");
	c2.print();
	printf("\n");
	a.print();
	printf(" * ");
	b.print();
	printf(" = ");
	c3.print();
	printf("\n");
	a.print();
	printf(" / ");
	b.print();
	printf(" = ");
	if (a2==0) printf("Inf");
	else c4.print();
	printf("\n");
	return 0;
}
