#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;
int main()
{
	unsigned short n,arr[10000];
	memset(arr,0,sizeof(arr));
	cin>>n;
	for (unsigned short i=0;i<n;i++) {
		short num;
		cin>>num;
		arr[abs(num-(i+1))]++;
	}
	for (short i=9999;i>=0;i--) {
		if (arr[i]>1) cout<<i<<' '<<arr[i]<<endl;
	}
	return 0;
}
