/*
1.这道题分数比较大小的方法值得注意
2.iostream头文件下有swap函数可以直接用
3.求最大公约数的函数gcd会写
*/
#include <iostream>
using namespace std;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int n1,m1,n2,m2,k,num=0,flag=0;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
	if (n1*m2>n2*m1) {
		swap(n1,n2);
		swap(m1,m2);
	}
	while (n1*k>=m1*num) num++;
	while (n1*k<m1*num&&n2*k>m2*num) {
		if (gcd(num,k)==1) {
			if (flag==1) cout<<' ';
			printf("%d/%d",num,k);
			if (flag==0) flag=1;
		}
		num++;
	}
	return 0;
}
