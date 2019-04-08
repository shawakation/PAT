#include <cstdio>
using namespace std;
int main()
{
	double sum=1.0;
	for (int j=0;j<3;j++) {
		double a1,a2,a3;
		scanf("%lf %lf %lf",&a1,&a2,&a3);
		if (a1>a2&&a1>a3) {
			printf("W");
			sum*=a1;
		}
		else if (a2>a1&&a2>a3) {
			printf("T");
			sum*=a2;
		}
		else if (a3>a1&&a3>a2) {
			printf("L");
			sum*=a3;
		}
		printf(" ");
	}
	printf("%.2lf",(sum*0.65-1)*2);
	return 0;
}
