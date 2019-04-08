#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m,countt;
	scanf("%d",&n);
	vector<long> arr1(n);
	for (int i=0; i<n; i++) scanf("%ld",&arr1[i]);
	scanf("%d",&m);
	vector<long> arr2(m);
	for (int i=0; i<m; i++) scanf("%ld",&arr2[i]);
	countt=(n+m-1)/2;
	vector<long> arr3;
	while (countt>=0&&!arr1.empty()&&!arr2.empty()) {
		if (arr1[0]>arr2[0]) {
			arr3.push_back(arr2[0]);
			arr2.erase(arr2.begin());
		} else if (arr1[0]<arr2[0]) {
			arr3.push_back(arr1[0]);
			arr1.erase(arr1.begin());
		} else {
			arr3.push_back(arr1[0]);
			arr1.erase(arr1.begin());
			arr2.erase(arr2.begin());
		}
		countt--;
	}
	while (countt>=0&&!arr1.empty()) {
		arr3.push_back(arr1[0]);
		arr1.erase(arr1.begin());
		countt--;
	}
	while (countt>=0&&!arr2.empty()) {
		arr3.push_back(arr2[0]);
		arr2.erase(arr2.begin());
		countt--;
	}
	cout<<arr3.back();
	return 0;
}
