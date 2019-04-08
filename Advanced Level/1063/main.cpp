/*
1.注意点：超时问题
*/
#include <iostream>
#include <unordered_set>
#define maxn 55
using namespace std;
unordered_set<long> arr[maxn];
int main()
{
	int n,k;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int m;
		scanf("%d",&m);
		for (int j=0;j<m;j++) {
			long num;
			scanf("%ld",&num);
			arr[i].insert(num);
		}
	}
	scanf("%d",&k);
	
	//注意点一
	for (int i=0;i<k;i++) {
		int a,b,samenum=0,totalnum;
		scanf("%d%d",&a,&b);
		totalnum=arr[b].size();
		for (auto p:arr[a]) {
			if (arr[b].find(p)!=arr[b].end()) samenum++;
			else totalnum++;
		}
		printf("%.1f%%\n",samenum*1.0/totalnum*100.0);
	}
	return 0;
}
