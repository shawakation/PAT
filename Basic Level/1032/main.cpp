/*
有点问题，用动态分配最后一个样例跑不通
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,max=0,maxschool=0;
	cin>>n;
	vector<int> arr(n);
	for (int i=0;i<n;i++) {
		int school,score;
		cin>>school>>score;
		arr[school]+=score;
		if (max<arr[school]) {
			max=arr[school];
			maxschool=school;
		}
	}
	cout<<maxschool<<' '<<max;
	return 0;
}
