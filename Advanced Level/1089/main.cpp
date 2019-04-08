#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> origin(n),change(n);
	for (int i=0; i<n; i++) scanf("%d",&origin[i]);
	for (int i=0; i<n; i++) scanf("%d",&after[i]);
	int i=1;
	for (; i<n; i++) {
		if (is_sorted(after.begin(),after.begin()+i)) {
			bool flag=0;
			for (int j=i+1; j<n; j++)
				if (after[j]!=origin[j]) {
					flag=1;
					break;
				}
			if (!flag) break;
		}
	}
	if (i<n) {
		printf("Insertion Sort\n");
		int t=after[++i];
		after.erase(after.begin()+i);
		int k=int(upper_bound(after.begin(),after.begin()+i,t)-after.begin());
		after.insert(after.begin()+k,t);
		for (int h=0; h<n; h++) {
			printf("%d",after[h]);
			if (h<n-1) printf(" ");
		}
		printf("\n");
	} else {
		printf("Merge Sort\n");
		int step=2;
		for (; step<=n; step*=2) {
			bool flag=0;
			for (int k=0; k<n; k+=step) {
				if (!is_sorted(after.begin()+k,after.begin()+min(k+step,n))) {
					flag=1;
					break;
				}
			}
			if (!flag) break;
		}
		step*=2;
		for (int k=0; k<n; k+=step) sort(after.begin()+k,after.begin()+min(k+step,n));
		for (int h=0; h<n; h++) {
			printf("%d",after[h]);
			if (h<n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
