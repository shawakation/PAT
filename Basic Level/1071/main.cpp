#include <iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	for (int i=0;i<k;i++) {
		int n1,b,t,n2;
		cin>>n1>>b>>t>>n2;
		if (t>n) cout<<"Not enough tokens.  Total = "<<n<<".\n";
		else if (n1>n2&&b==0||n1<n2&&b==1) {
			n+=t;
			cout<<"Win "<<t<<"!  Total = "<<n<<".\n";
		}
		else if (n1>n2&&b==1||n1<n2&&b==0) {
			n-=t;
			cout<<"Lose "<<t<<".  Total = "<<n<<".\n";
			if (n<=0) {
				cout<<"Game Over.\n";
				return 0;
			}
		}
	}
	return 0;
}
