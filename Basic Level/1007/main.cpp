#include <iostream>
#include <cmath>
using namespace std;
bool judgesushu(unsigned long k)
{
	for (unsigned long c=2;c<=(unsigned long)sqrt(k);c++) {
		if (k%c==0) return false;
	}
	return true;
}
int main()
{
	unsigned long N,countc=0;
	cin>>N;
	unsigned long k=2;
	for (unsigned long j=k+1;j<=N;j++)
		if (judgesushu(j)) {
			if (j-k==2) countc++;
			k=j;
			j=k+1;
		}
	cout<<countc;
	return 0;
}
