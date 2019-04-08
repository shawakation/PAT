#include <cstdio>
using namespace std;
int main()
{
	int a1,a2,b[3];
	scanf("%d %d",&a1,&a2);
	for (int i=0;i<3;i++) scanf("%d",&b[i]);
	int jia1=0,yi1=0;
	for (int i=0;i<3;i++) {
		if (b[i]==0) jia1++;
		else if (b[i]==1) yi1++;
	}
	if (a1>a2&&jia1>0||a1<a2&&jia1==3)
		printf("The winner is a: %d + %d",a1,jia1);
	else if (a1<a2&&yi1>0||a1>a2&&yi1==3)
		printf("The winner is b: %d + %d",a2,yi1);
	return 0;
}
