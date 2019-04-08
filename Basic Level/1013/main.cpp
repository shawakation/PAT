#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
bool judgesushu(unsigned long long i)
{
	for (unsigned long long k=2;k<=(unsigned long long)sqrt(i);k++)
		if (i%k==0) return false;
	return true;
}
int main()
{
	unsigned int m,n,countt=0;
	unsigned long long start=2;
	deque<unsigned long long> sushu;
	cin>>m>>n;
	while (sushu.size()!=n) {
		if (judgesushu(start))
			sushu.push_back(start);
		start++;
	}
	for (unsigned int i=m-1;i<n;i++) {
		cout<<sushu.at(i);
		countt++;
		if (i==n-1) break;
		if (countt%10!=0) cout<<' ';
		else cout<<endl;
	}
	return 0;
}
