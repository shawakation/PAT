#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double maxdis=0,mindis=99999;
	string winner,loser;
	cin>>n;
	for (int i=0;i<n;i++) {
		string num;
		int x,y;
		cin>>num>>x>>y;
		double distance=sqrt(pow(x,2)+pow(y,2));
		if (distance>maxdis) {
			maxdis=distance;
			winner=num;
		}
		if (distance<mindis) {
			mindis=distance;
			loser=num;
		}
	}
	cout<<loser<<' '<<winner;
	return 0;
}
