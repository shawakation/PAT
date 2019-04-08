#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n;n
	cin>>n;n
	int *a=new int[n];
	int *b=new int[n];
	for (int k=0;k<n;k++) cin>>a[k];
	for (int k=0;k<n;k++) cin>>b[k];
	int k=0;
	for (;b[k]<=b[k+1]&&k<n-1;k++) ;
	int i=k+1;
	for (k++;k<n&&a[k]==b[k];k++) ;
	if (k==n) {
		cout<<"Insertion Sort\n";
		sort(b,b+i+1);
		for (int j=0;j<n;j++) {
			cout<<b[j];
			if (j!=n-1) cout<<' ';
		}
		return 0;
	}
	else {
		cout<<"Merge Sort\n";
		int t=1;
		for (;2*t<10;t++) ;
		for (int aa=1;aa<=t;aa++) {
			bool flag=true;
			int bb=aa*2;
			for (int cc=0;cc<n;cc+=bb) sort(a+cc,a+cc+bb);
			for (int dd=0;dd<n;dd++)
				if (a[dd]!=b[dd]) flag=false;
			if (flag) {
				aa++;
				int bb1=aa*2;
				for (int cc1=0;cc1<n;cc1+=bb1) sort(a+cc1,a+cc1+bb1);
				for (int j=0;j<n;j++) {
					cout<<a[j];
					if (j!=n-1) cout<<' ';
				}
				return 0;
			}
		}
	}
	return 0;
}
