#include <iostream>
using namespace std;
int main()
{
	int n,sum=0,i=1,a=1;
	scanf("%d",&n);
	while (a<=n) {
		sum+=i;
		i*=(++a);
	}
	printf("%d\n",sum);
	return 0;
}
