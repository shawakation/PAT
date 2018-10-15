#include <iostream>
using namespace std;
int main()
{
	unsigned short n;
	cin>>n;
	unsigned short a=n/100;
	n=n%100;
	for (unsigned short i=0;i<a;i++) cout<<'B';
	a=n/10;
	n=n%10;
	for (unsigned short i=0;i<a;i++) cout<<'S';
	for (unsigned short i=1;i<=n;i++) cout<<i;
	cout<<endl;
	return 0;
}
