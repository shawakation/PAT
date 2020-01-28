#include <cstdio>
#include <vector>
using namespace std;
struct person
{
	char name[15],sex,guhua[20],shouji[20],riqi[20];
};
int main()
{
	int n,m;
	scanf("%d",&n);
	vector<person> arr;
	for (int i=0;i<n;i++) {
		person ren;
		scanf("%s %s %c %s %s",ren.name,ren.riqi,&ren.sex,ren.guhua,ren.shouji);
		arr.push_back(ren);
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int k;
		scanf("%d",&k);
		if (k>n-1||k<0) printf("Not Found\n");
		else printf("%s %s %s %c %s\n",arr[k].name,arr[k].guhua,arr[k].shouji,arr[k].sex,arr[k].riqi);
	}
	return 0;
}
