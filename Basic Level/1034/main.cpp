/*
1.求最大公约数的函数：return b==0?a:gcd(b,a%b);
2.注意用分数运算法则可能出现分母小于0的情况
(有两个样例跑不对)
*/
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
void huajian(int a,int b)
{
	if (a<0) {
		a=abs(a);
		if (a<b) {
			int k=gcd(a,b);
			if (k!=1) {
				a/=k;
				b/=k;
			}
			printf("(-%d/%d)",a,b);
		}
		else {
			int c=a/b;
			a-=c*b;
			if (a!=0) {
				int k=gcd(a,b);
				if (k!=1) {
					a/=k;
					b/=k;
				}
				printf("(-%d %d/%d)",c,a,b);
			}
			else printf("(-%d)",c);
		}
	}
	else if (a==0) cout<<0;
	else {
		if (a<b) {
			int k=gcd(a,b);
			if (k!=1) {
				a/=k;
				b/=k;
			}
			printf("%d/%d",a,b);
		}
		else {
			int c=a/b;
			a-=c*b;
			if (a!=0) {
				int k=gcd(a,b);
				if (k!=1) {
					a/=k;
					b/=k;
				}
				printf("%d %d/%d",c,a,b);
			}
			else printf("%d",c);
		}
	}
}
void swapp(int &a,int &b)
{
	if (a<0&&b<0) {
		a=abs(a);
		b=abs(b);
	}
	else if (a>0&&b<0) {
		a=-a;
		b=abs(b);
	}
}
int main()
{
	int a1,b1,a2,b2;
	scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
	int c1=a1*b2+a2*b1;
	int c2=b1*b2;
	swapp(c1,c2);
	huajian(a1,b1);
	cout<<" + ";
	huajian(a2,b2);
	cout<<" = ";
	huajian(c1,c2);
	cout<<endl;
	int d1=a1*b2-a2*b1;
	int d2=b1*b2;
	swapp(d1,d2);
	huajian(a1,b1);
	cout<<" - ";
	huajian(a2,b2);
	cout<<" = ";
	huajian(d1,d2);
	cout<<endl;
	int e1=a1*a2;
	int e2=b1*b2;
	swapp(e1,e2);
	huajian(a1,b1);
	cout<<" * ";
	huajian(a2,b2);
	cout<<" = ";
	huajian(e1,e2);
	cout<<endl;
	huajian(a1,b1);
	cout<<" / ";
	huajian(a2,b2);
	cout<<" = ";
	if (a1==0) cout<<"0";
	else if (a2==0) cout<<"Inf";
	else {
		int f1=a1*b2;
		int f2=a2*b1;
		swapp(f1,f2);
		huajian(f1,f2);
	}
	cout<<endl;
	return 0;
}
