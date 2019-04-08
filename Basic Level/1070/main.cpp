/*
重点注意此题的逻辑，逻辑性很强
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for (int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	unsigned long sum=arr[0];
	for (int i=1;i<n;i++) sum=(sum+arr[i])/2;
	cout<<sum;
	return 0;
}
