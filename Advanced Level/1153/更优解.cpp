/*
1.要点：边输入边处理，把每种情况都处理下来
*/
#include <bits/stdc++.h>
using namespace std;
struct stu
{
	string cardnum;
	int score;
	stu(string _card,int _s) {
		cardnum=_card;score=_s;
	}
	friend bool operator < (const stu &a,const stu &b)
	{
		if (a.score!=b.score) return a.score>b.score;
		else return a.cardnum<b.cardnum;
	}
};
struct site
{
	int totalnum,totalscore;
	site() {
		totalnum=totalscore=0;
	}
};
struct datet
{
	string site;
	int num;
	datet(string _s,int _n) {
		site=_s;num=_n;
	}
	friend bool operator < (const datet &a,const datet &b) {
		if (a.num!=b.num) return a.num>b.num;
		else return a.site<b.site;
	}
};
unordered_map<char,set<stu> > ans1;
unordered_map<string,site> ans2;
unordered_map<string,unordered_map<string,int> > ans3;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		string cardnum;
		int score;
		cin>>cardnum;
		scanf("%d",&score);
		ans1[cardnum[0]].insert(stu(cardnum,score));
		ans2[cardnum.substr(1,3)].totalnum++;
		ans2[cardnum.substr(1,3)].totalscore+=score;
		ans3[cardnum.substr(4,6)][cardnum.substr(1,3)]++;
	}
	for (int i=0;i<m;i++) {
		int type;
		scanf("%d",&type);
		switch (type) {
			case 1:{
				char query;
				cin>>query;
				printf("Case %d: %d %c\n",i+1,type,query);
				if (ans1.find(query)==ans1.end()) printf("NA\n");
				else for (auto &p:ans1[query]) printf("%s %d\n",p.cardnum.c_str(),p.score);
				break;
			}
			case 2:{
				string query;
				cin>>query;
				printf("Case %d: %d %s\n",i+1,type,query.c_str());
				if (ans2.find(query)==ans2.end()) printf("NA\n");
				else printf("%d %d\n",ans2[query].totalnum,ans2[query].totalscore);
				break;
			}
			case 3:{
				string query;
				cin>>query;
				printf("Case %d: %d %s\n",i+1,type,query.c_str());
				if (ans3.find(query)==ans3.end()) printf("NA\n");
				else {
					set<datet> ans;
					for (auto &p:ans3[query]) ans.insert(datet(p.first,p.second));
					for (auto &p:ans) printf("%s %d\n",p.site.c_str(),p.num);
				}
				break;
			}
		}
	}
	return 0;
}
