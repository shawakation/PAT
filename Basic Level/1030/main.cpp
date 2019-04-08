/*
本题关键是想到排序
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	long n;
	long long p;
	int result=0;
	cin>>n>>p;
	vector<long> v(n);
	for (long i=0;i<n;i++) cin>>v[i];
	sort(v.begin(),v.end());
	for (long i=0;i<n;i++)
		for (long j=i+result;j<n;j++)
			if (v[i]*p>=v[j]) {
				int temp=j-i+1;
				if (temp>result) result=temp;
			}
			else break;
	cout<<result;
	return 0;
}
