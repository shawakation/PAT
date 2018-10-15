/*
注意此题逻辑上的漏洞
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int d,n;
	cin>>d>>n;
	vector<int> arr;
	vector<int> arr2;
	arr.push_back(d);
	for (int k1=1;k1<n;k1++) {
		for (int i=0;i<arr.size();) {
			int k=i;
			while (arr[k]==arr[i]&&k<arr.size()) k++;
			arr2.push_back(arr[i]);
			arr2.push_back(k-i);
			i=k;
		}
		arr.clear();
		for (int j=0;j<arr2.size();j++) {
			arr.push_back(arr2[j]);
		}
		arr2.clear();
	}
	for (int k=0;k<arr.size();k++) cout<<arr.at(k);
	return 0;
}
