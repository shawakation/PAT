#include <iostream>
using namespace std;
int main()
{
	unsigned short n;
	unsigned int sum=0;
	cin>>n;
	short *arr=new short[n];
	for (unsigned short i=0;i<n;i++) cin>>arr[i];
	for (unsigned short i=0;i<n-1;i++)
		for (unsigned short j=i+1;j<n;j++) {
			sum+=arr[i]*10+arr[j];
			sum+=arr[j]*10+arr[i];
		}
	cout<<sum;
	return 0;
}
