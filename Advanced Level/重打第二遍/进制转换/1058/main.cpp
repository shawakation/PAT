#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[3],b[3],c[3];
	scanf("%d.%d.%d %d.%d.%d",a,a+1,a+2,b,b+1,b+2);
	int carry=(a[2]+b[2])/29;
	c[2]=(a[2]+b[2])%29;
	c[1]=(a[1]+b[1]+carry)%17;
	carry=(a[1]+b[1]+carry)/17;
	c[0]=a[0]+b[0]+carry;
	printf("%d.%d.%d",c[0],c[1],c[2]);
	return 0;
}
