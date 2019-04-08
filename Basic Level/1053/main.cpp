/*
1.printf 格式控制符中 %% 代表%本身
*/
#include <iostream>
using namespace std;
int main()
{
	int n,d,maybekong=0,kong=0;
	float e;
	cin>>n>>e>>d;
	for (int i=0;i<n;i++) {
		int k,maybecount=0;
		cin>>k;
		for (int j=0;j<k;j++) {
			float elec;
			cin>>elec;
			if (elec<e) maybecount++;
		}
		if (maybecount>k/2)
			if (k>d) kong++;
			else maybekong++;
	}
	printf("%.1lf%% ",(float)maybekong/(float)n*100);
	printf("%.1lf%%",(float)kong/(float)n*100);
	return 0;
}
