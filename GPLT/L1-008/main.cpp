#include <cstdio>
using namespace std;
int main()
{
	int a,b,sumt=0,countt=1;
	scanf("%d %d",&a,&b);
	for (int i=a;i<=b;i++,countt++) {
		printf("%5d",i);
		sumt+=i;
		if (countt%5==0) printf("\n");
	}
	if ((countt-1)%5!=0) printf("\n");
	printf("Sum = %d",sumt);
	return 0;
}
