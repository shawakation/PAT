#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu
{
	int id,rank;
	int Ge,Gi;
	double Gf;
	int choice[5];
	stu() {
		rank=id=Ge=Gi=0;
		Gf=0.0f;
		for (int i=0;i<5;i++) choice[i]=-1;
	}
};
struct school
{
	vector<stu> admin;
	int quota;
};
bool cmp(struct stu a,struct stu b)
{
	if (a.Gf!=b.Gf) return a.Gf>b.Gf;
	else return a.Ge>b.Ge;
}
bool cmp2(struct stu a,struct stu b)
{
	return a.id<b.id;
}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<school> schools(m);
	vector<stu> stus;
	for (int i=0;i<m;i++) {
		scanf("%d",&schools[i].quota);
	}
	for (int i=0;i<n;i++) {
		stu aa;
		scanf("%d%d",&aa.Ge,&aa.Gi);
		aa.Gf=(aa.Ge+aa.Gi)/2.0;
		for (int j=0;j<k;j++) scanf("%d",&aa.choice[j]);
		aa.id=i;
		stus.push_back(aa);
	}
	sort(stus.begin(),stus.end(),cmp);
	stus[0].rank=1;
	for (int i=1;i<n;i++) {
		if (stus[i].Gf==stus[i-1].Gf&&stus[i].Ge==stus[i-1].Ge) stus[i].rank=stus[i-1].rank;
		else stus[i].rank=i+1;
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<k;j++) {
			if (schools[stus[i].choice[j]].admin.size()<schools[stus[i].choice[j]].quota) {
				schools[stus[i].choice[j]].admin.push_back(stus[i]);
				break;
			}
			else if (schools[stus[i].choice[j]].admin.size()>0&&schools[stus[i].choice[j]].admin.at(schools[stus[i].choice[j]].admin.size()-1).rank==stus[i].rank) {
				schools[stus[i].choice[j]].admin.push_back(stus[i]);
				break;
			}
		}
	}
	for (int i=0;i<m;i++) {
		if (!schools[i].admin.empty()) {
			sort(schools[i].admin.begin(),schools[i].admin.end(),cmp2);
			for (int k=0;k<schools[i].admin.size();k++) {
				printf("%d",schools[i].admin.at(k).id);
				if (k!=schools[i].admin.size()-1) printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
