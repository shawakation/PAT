#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
int main()
{
	int n,m;
	multiset<int> arr;
	unordered_map<int,int> my;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		arr.insert(t);
		my[t]++;
	}
	for (auto &p:arr) {
		my[p]--;
		if (p<=m-p&&my.find(m-p)!=my.end()&&my[m-p]>0) {
			printf("%d %d",p,m-p);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
