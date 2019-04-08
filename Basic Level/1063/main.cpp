#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	float maxmo=0;
	cin>>n;
	for (int i=0;i<n;i++) {
		int x,y;
		cin>>x>>y;
		float mo=sqrt(pow(x,2)+pow(y,2));
		if (mo>maxmo) maxmo=mo;
	}
	printf("%.2f",maxmo);
	return 0;
}
