#include <iostream>
using namespace std;
int main()
{
	unsigned short n,countc=0;
	cin>>n;
	while (n!=1) {
		if (n%2==0) n=n/2;
		else n=(3*n+1)/2;
		countc++;
	}
	cout<<countc<<endl;
	return 0;
}
