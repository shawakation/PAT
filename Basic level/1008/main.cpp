#include <iostream>
using namespace std;
int main()
{
	unsigned short n;
	unsigned int m;
	cin>>n>>m;
	int *arr=new int[n+1];
	for (unsigned short i=0;i<n;i++) cin>>arr[i];
	for (unsigned int k=0;k<m;k++) {
		for (short i=n-1;i>=0;i--) arr[i+1]=arr[i];
		arr[0]=arr[n];
	}
	for (unsigned short i=0;i<n;i++) {
		cout<<arr[i];
		if (i!=n-1) cout<<' ';
	}
	return 0;
}
