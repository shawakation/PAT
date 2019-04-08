#include <bits/stdc++.h>
using namespace std;
struct school
{
	string name;
	int TWS,scoreA,scoreB,scoreT,testeenum,rank;
	school() {
		TWS=scoreA=scoreB=scoreT=testeenum=rank=0;
	}
};
unordered_map<string,school> my;
vector<school> ans;
bool cmp(const school &a,const school &b)
{
	if (a.TWS!=b.TWS) return a.TWS>b.TWS;
	else if (a.testeenum!=b.testeenum) return a.testeenum<b.testeenum;
	else return a.name<b.name;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char testid[9];
		int score;
		string site;
		scanf("%s %d",testid,&score);
		cin>>site;
		for (auto &p:site) if (isupper(p)) p=tolower(p);
		if (testid[0]=='B') my[site].scoreB+=score;
		else if (testid[0]=='A') my[site].scoreA+=score;
		else if (testid[0]=='T') my[site].scoreT+=score;
		my[site].testeenum++;
	}
	for (auto &p:my) {
		p.second.name=p.first;
		p.second.TWS=(int)(p.second.scoreB/1.5+p.second.scoreA*1.0+p.second.scoreT*1.5);
		ans.push_back(p.second);
	}
	sort(ans.begin(),ans.end(),cmp);
	ans[0].rank=1;
	for (int i=1;i<ans.size();i++)
		if (ans[i].TWS==ans[i-1].TWS) ans[i].rank=ans[i-1].rank;
		else ans[i].rank=i+1;
	printf("%d\n",ans.size());
	for (auto &p:ans) printf("%d %s %d %d\n",p.rank,p.name.c_str(),p.TWS,p.testeenum);
	return 0;
}
