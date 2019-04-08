/*
1.本题有很难发现的错误点   发现不了算了 反正才1分
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double r1,p1,r2,p2;
	cin>>r1>>p1>>r2>>p2;
	double A=r1*r2*cos(p1+p2);
	double B=r1*r2*sin(p1+p2);
	if (A<0&&A+0.005>=0) cout<<"0.00";
	else printf("%.2lf",A);
	if (B<0&&B+0.005>=0) cout<<"+0.00i";
	else if (B<0) printf("-%.2lfi",fabs(B));
	else printf("+%.2lfi",B);
	return 0;
}
