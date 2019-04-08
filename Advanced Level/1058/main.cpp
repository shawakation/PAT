#include <iostream>
using namespace std;
class money
{
	public:
		int Gallon,Sickle,Knut;
	public:
		money() {
			Gallon=Sickle=Knut=0;
		}
		money(int a,int b,int c) {
			Gallon=a;
			Sickle=b;
			Knut=c;
		}
		long long calc() {
			return (long long)(Gallon*29*17+Sickle*29+Knut);
		}
		void convert(long long s) {
			Gallon=s/(29*17);
			s-=Gallon*29*17;;
			Sickle=s/29;
			s-=Sickle*29;
			Knut=s;
		}
};
int main()
{
	int a,b,c,d,e,f;
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
	money m1(a,b,c),m2(d,e,f),m3;
	long long sum=m1.calc()+m2.calc();
	m3.convert(sum);
	printf("%d.%d.%d",m3.Gallon,m3.Sickle,m3.Knut);
	return 0;
}
