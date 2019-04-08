/*
1.printf与scanf比cin和cout快，数据量大的题用printf和scanf不会超时
2.这个不是最优解，最优解可以考虑在person中加入flag表示是第几类
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct person
{
	char id[10];
	int vir,tal,total;
};
bool cmp(struct person a,struct person b)
{
	if (a.total==b.total) {
		if (a.vir==b.vir) return strcmp(a.id,b.id)<0;
		else return a.vir>b.vir;
	}
	else return a.total>b.total;
}
int main()
{
	vector<person> arr[4];
	int n,l,h,sum=0;
	scanf("%d %d %d",&n,&l,&h);
	for (int i=0;i<n;i++) {
		person p;
		scanf("%s %d %d",p.id,&p.vir,&p.tal);
		p.total=p.vir+p.tal;
		if (p.vir>=l&&p.tal>=l) {
			sum++;
			if (p.vir>=h&&p.tal>=h) arr[0].push_back(p);
			else if (p.vir>=h&&p.tal<h) arr[1].push_back(p);
			else if (p.vir<h&&p.tal<h&&p.vir>=p.tal) arr[2].push_back(p);
			else arr[3].push_back(p);
		}
	}
	for (int i=0;i<4;i++) sort(arr[i].begin(),arr[i].end(),cmp);
	printf("%d\n",sum);
	for (int i=0;i<4;i++) {
		for (int j=0;j<arr[i].size();j++)
			printf("%s %d %d\n",arr[i][j].id,arr[i][j].vir,arr[i][j].tal);
	}
	return 0;
}
