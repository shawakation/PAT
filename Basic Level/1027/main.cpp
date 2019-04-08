#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	short n;
	char ss;
	cin>>n>>ss;
	short ceng=(short)sqrt((n+1)/2);
	short cha=n-(2*pow(ceng,2)-1);
	for (short a=0;a<ceng;a++) {
		for (short i=0;i<a;i++) cout<<' ';
		for (short i=0;i<2*(ceng-a)-1;i++) cout<<ss;
		cout<<endl;
	}
	for (short a=ceng-2;a>=0;a--) {
		for (short i=0;i<a;i++) cout<<' ';
		for (short i=0;i<2*(ceng-a)-1;i++) cout<<ss;
		cout<<endl;
	}
	cout<<cha;
	return 0;
}
