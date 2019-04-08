#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n,m,count=0;
	scanf("%d %d",&n,&m);
	vector<int> arr(n);
	for (int i=0;i<n;i++) scanf("%d",&arr[i]);
	m%=n;
	for (int i=n-m;i<n;i++) {
		printf("%d",arr[i]);
		count++;
		if (count!=n) printf(" ");
	}
	for (int i=0;i<n-m;i++) {
		printf("%d",arr[i]);
		count++;
		if (count!=n) printf(" ");
	}
	return 0;
}
