/*
×¢ÒâÂß¼­£¡
*/
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int n,m,sum=0;
	scanf("%d",&n);
	vector<int> arr(n+1);
	for (int i=1;i<=n;i++) {
		int a;
		scanf("%d",&a);
		sum+=a;
		arr[i]=sum;
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		if (b<a) swap(a,b);
		int dis1=arr[b-1]-arr[a-1];
		int dis2=sum-dis1;
		if (dis1>dis2) printf("%d\n",dis2);
		else printf("%d\n",dis1);
	}
	return 0;
}
