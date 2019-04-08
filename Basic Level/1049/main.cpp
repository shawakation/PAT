#include <iostream>
using namespace std;
float sum(float arr[],int a,int b)
{
	float sum3=0;
	for (int k=a;k<=b;k++) sum3+=arr[k];
	return sum3;
}
int main()
{
	int n;
	cin>>n;
	float *a=new float[n];
	float sum2=0;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) {
		for (int j=i;j<n;j++) sum2+=sum(a,i,j);
	}
	printf("%.2f",sum2);
	return 0;
}
