#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,floor=0;
	long timet=0;
	scanf("%d",&n);
	vector<int> arr(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	for (int i=0;i<n;i++) {
		if (arr[i]>floor) timet+=(arr[i]-floor)*6;
		else if (arr[i]<floor) timet+=(floor-arr[i])*4;
		floor=arr[i];
		timet+=5;
	}
	printf("%ld",timet);
	return 0;
}
