#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	unsigned short n;
	char aa;
	cin>>n>>aa;
	for (unsigned short i=0;i<n;i++) cout<<aa;
	cout<<endl;
	unsigned short n2=round((float)n/2.0f);
	for (unsigned short i=1;i<=n2-2;i++) {
		cout<<aa;
		for (unsigned short i=0;i<n-2;i++) cout<<' ';
		cout<<aa<<endl;
	}
	for (unsigned short i=0;i<n;i++) cout<<aa;
	cout<<endl;
	return 0;
}
