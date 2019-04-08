#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct kaosheng
{
	string id;
	int loc_num;
	int loc_rank;
	int total_rank;
	int grade;
};
bool cmp(struct kaosheng a,struct kaosheng b)
{
	if (a.grade!=b.grade) return a.grade>b.grade;
	else if (a.id!=b.id) return a.id<b.id;
}
int main()
{
	int n;
	vector<kaosheng> zong;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int m;
		vector<kaosheng> loc;
		scanf("%d",&m);
		for (int k=0;k<m;k++) {
			kaosheng aa;
			cin>>aa.id;
			scanf("%d",&aa.grade);
			aa.loc_num=i+1;
			loc.push_back(aa);
		}
		sort(loc.begin(),loc.end(),cmp);
		loc[0].loc_rank=1;
		for (int j=1;j<loc.size();j++)
			if (loc[j].grade==loc[j-1].grade) loc[j].loc_rank=loc[j-1].loc_rank;
			else loc[j].loc_rank=j+1;
		for (int j=0;j<loc.size();j++) zong.push_back(loc[j]);
	}
	sort(zong.begin(),zong.end(),cmp);
	printf("%d\n",zong.size());
	zong[0].total_rank=1;
	for (int i=1;i<zong.size();i++)
		if (zong[i].grade==zong[i-1].grade) zong[i].total_rank=zong[i-1].total_rank;
		else zong[i].total_rank=i+1;
	for (int i=0;i<zong.size();i++) {
		cout<<zong[i].id<<' ';
		printf("%d %d %d\n",zong[i].total_rank,zong[i].loc_num,zong[i].loc_rank);
	}
	return 0;
}
