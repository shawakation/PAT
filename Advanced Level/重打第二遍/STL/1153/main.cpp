#include <bits/stdc++.h>
using namespace std;
struct kaosheng
{
	string num;
	int score;
	kaosheng(string _a,int _b) {
		num=_a;score=_b;
	}
	friend bool operator < (const kaosheng &a,const kaosheng &b) {
		if (a.score!=b.score) return a.score>b.score;
		else return a.num<b.num;
	}
};
struct site
{
	int peoplenum,totalscore;
	site() {
		peoplenum=totalscore=0;
	}
};
struct datet
{
	string sitenum;
	int peoplenum;
	datet(string _a,int _b) {
		sitenum=_a;peoplenum=_b;
	}
	friend bool operator < (const datet &a,const datet &b) {
		if (a.peoplenum!=b.peoplenum) return a.peoplenum>b.peoplenum;
		else return a.sitenum<b.sitenum;
	}
};
unordered_map<char,vector<kaosheng> > query1;
unordered_map<string,site> query2;
unordered_map<string,unordered_map<string,int> > query3;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		string s;
		int c;
		cin>>s;
		scanf("%d",&c);
		query1[s[0]].push_back(kaosheng(s,c));
		query2[s.substr(1,3)].peoplenum++;
		query2[s.substr(1,3)].totalscore+=c;
		query3[s.substr(4,6)][s.substr(1,3)]++;
	}
	for (int i=1;i<=m;i++) {
		int t;
		scanf("%d ",&t);
		switch (t) {
			case 1:{
				char f;
				scanf("%c",&f);
				printf("Case %d: %d %c\n",i,t,f);
				if (query1.find(f)==query1.end()) printf("NA\n");
				else {
					vector<kaosheng> re(query1[f]);
					sort(re.begin(),re.end());
					for (auto &p:re) printf("%s %d\n",p.num.c_str(),p.score);
				}
				break;
			}
			case 2:{
				string q;
				cin>>q;
				printf("Case %d: %d %s\n",i,t,q.c_str());
				if (query2.find(q)==query2.end()) printf("NA\n");
				else printf("%d %d\n",query2[q].peoplenum,query2[q].totalscore);
				break;
			}
			case 3:{
				string q;
				cin>>q;
				printf("Case %d: %d %s\n",i,t,q.c_str());
				if (query3.find(q)==query3.end()) printf("NA\n");
				else {
					vector<datet> re;
					for (auto &p:query3[q]) re.push_back(datet(p.first,p.second));
					sort(re.begin(),re.end());
					for (auto &p:re) printf("%s %d\n",p.sitenum.c_str(),p.peoplenum);
				}
				break;
			}
		}
	}
	return 0;
}
