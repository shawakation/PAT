#include <cstdio>
using namespace std;
int main()
{
	long Gallon1,Gallon2,Sickle1,Knut1,Sickle2,Knut2;
	scanf("%ld.%ld.%ld %ld.%ld.%ld",&Gallon1,&Sickle1,&Knut1,&Gallon2,&Sickle2,&Knut2);
	long money1=(Gallon1*17+Sickle1)*29+Knut1;
	long money2=(Gallon2*17+Sickle2)*29+Knut2;
	long charge=money2-money1;
	if (charge<0) {
		printf("-");
		charge=-charge;
	}
	long Gallon=charge/(17*29);
	long Sickle=(charge-Gallon*17*29)/29;
	long Knut=charge-(Gallon*17+Sickle)*29;
	printf("%ld.%ld.%ld\n",Gallon,Sickle,Knut);
	return 0;
}
