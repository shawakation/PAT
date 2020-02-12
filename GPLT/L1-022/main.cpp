#include <cstdio>
using namespace std;
int main()
{
	int n,ji=0,ou=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int k;
		scanf("%d",&k);
		if (k%2==0) ou++;
		else ji++;
	}
	printf("%d %d\n",ji,ou);
	return 0;
}
