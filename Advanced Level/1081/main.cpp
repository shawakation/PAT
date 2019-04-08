/*
1.溢出问题：long * long 可能会溢出
            加法时必须每次加之后都约分，否则最后可能溢出
2.注意分子可能是负数，因此判断时要注意
3.结构体可以和类一样写
*/
#include <iostream>
#include <cmath>
using namespace std;
long gcd(long a,long b)
{
	return !b?a:gcd(b,a%b);
}
struct frac {
	public:
		long up,down;
	public:
		frac(long a,long b) {
			up=a;
			down=b;
		}
		void reduction() {
			if (down<0) {
				up=-up;
				down=-down;
			}
			long gcdt=gcd(abs(up),abs(down));
			up/=gcdt;
			down/=gcdt;
		}
		void print() {
			if (up==0) printf("0");
			else if (up>down)
				if (up%down==0) printf("%ld",up/down);
				else printf("%ld %ld/%ld",up/down,up%down,down);
			else printf("%ld/%ld",up,down);
		}
		frac operator + (frac &t) {
			frac temp(up*t.down+down*t.up,down*t.down);
			temp.reduction();
			return temp;
		}
};
int main()
{
	frac sum(0,1);
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		long a,b;
		scanf("%ld/%ld",&a,&b);
		frac tt(a,b);
		sum=sum+tt;
	}
	sum.print();
	return 0;
}
