#include <iostream>
#include <cmath>
using namespace std;
bool isprime(unsigned long x) {
	if (x==1) return 0;
	else {
		for (int i=2;i<=int(sqrt(x));i++)
			if (x%i==0) return 0;
		return 1;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		unsigned long m;
		scanf("%lu",&m);
		printf(isprime(m)?"Yes\n":"No\n");
	}
	return 0;
}
