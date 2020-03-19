#include <bits/stdc++.h>
using namespace std;
struct stu
{
	char num[15];
	int score,localrank,totalrank,locid;
};
vector<stu> ans;
bool cmp(const stu &a,const stu &b)
{
	if (a.score!=b.score) return a.score>b.score;
	else return strcmp(a.num,b.num)<0;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		vector<stu> temp;
		for (int j=0;j<k;j++) {
			stu tt;
			scanf("%s %d",tt.num,&tt.score);
			tt.locid=i;
			temp.push_back(tt);
		}
		sort(temp.begin(),temp.end(),cmp);
		temp[0].localrank=1;
		ans.push_back(temp[0]);
		for (int j=1;j<k;j++) {
			if (temp[j].score==temp[j-1].score) temp[j].localrank=temp[j-1].localrank;
			else temp[j].localrank=j+1;
			ans.push_back(temp[j]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	ans[0].totalrank=1;
	for (int i=1;i<ans.size();i++) {
		if (ans[i].score==ans[i-1].score) ans[i].totalrank=ans[i-1].totalrank;
		else ans[i].totalrank=i+1;
	}
	printf("%d\n",ans.size());
	for (auto &p:ans) printf("%s %d %d %d\n",p.num,p.totalrank,p.locid,p.localrank);
	return 0;
}
