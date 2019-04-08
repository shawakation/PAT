/*
1.printf()中的输出格式控制：
		%%  %d  %04d  %f  %lf  %.2lf  %.2f  %s  %c
*/
#include <iostream>
using namespace std;
int main()
{
	unsigned short n;
	cin>>n;
	if (n==0) {
		cout<<"N N N N N";
		return 0;
	}
	unsigned short *arr=new unsigned short[n];
	for (unsigned short i=0;i<n;i++) cin>>arr[i];
	unsigned int a1=0,a3=0,a4count=0,a4num=0,a5count=0,a2count=0;
	unsigned short a5=arr[0];
	int a2=0;
	short sign=1;
	for (unsigned short i=0;i<n;i++)
		switch (arr[i]%5) {
			case 0:{
				if (arr[i]%2==0) a1+=arr[i];
				break;
			}
			case 1:{
				a2+=arr[i]*sign;
				sign*=(-1);
				a2count++;
				break;
			}
			case 2:{
				a3++;
				break;
			}
			case 3:{
				a4count+=arr[i];
				a4num++;
				break;
			}
			case 4:{
				if (arr[i]>a5) a5=arr[i];
				a5count++;
				break;
			}
		}
	float a4=(float)a4count/(float)a4num;
	if (a1==0) cout<<'N'<<' ';
	else cout<<a1<<' ';
	if (a2count==0) cout<<'N'<<' ';
	else cout<<a2<<' ';
	if (a3==0) cout<<'N'<<' ';
	else cout<<a3<<' ';
	if (a4num==0) cout<<'N'<<' ';
	else printf("%.1f ",a4);
	if (a5count==0) cout<<'N';
	else cout<<a5;
	return 0;
}
