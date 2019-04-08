#include <bits/stdc++.h>
using namespace std;
struct stu
{
	string cardnum;
	int score;
};
vector<stu> arr;
bool cmp1(const stu &a,const stu &b)
{
	return a.cardnum[0]<b.cardnum[0];
}
bool cmp2(const stu &a,const stu &b)
{
	return a.cardnum.substr(1,3)<b.cardnum.substr(1,3);
}
bool cmp3(const stu &a,const stu &b)
{
	return a.cardnum.substr(4,6)<b.cardnum.substr(4,6);
}
bool cmpans(const stu &a,const stu &b)
{
	if (a.score!=b.score) return a.score>b.score;
	else return a.cardnum<b.cardnum;
}
bool cmpans2(const pair<string,int> &a,const pair<string,int> &b)
{
	if (a.second!=b.second) return a.second>b.second;
	else return a.first<b.first;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) {
		stu tt;
		cin>>tt.cardnum;
		scanf("%d",&tt.score);
		arr.push_back(tt);
	}
	for (int i=0;i<m;i++) {
		int type;
		scanf("%d",&type);
		switch (type) {
			case 1:{
				char query;
				cin>>query;
				vector<stu> ans;
				sort(arr.begin(),arr.end(),cmp1);
				int g=0;
				while (g<arr.size()&&arr[g].cardnum[0]!=query) g++;
				for (;g<arr.size()&&arr[g].cardnum[0]==query;g++) ans.push_back(arr[g]);
				sort(ans.begin(),ans.end(),cmpans);
				printf("Case %d: %d %c\n",i+1,type,query);
				if (ans.empty()) printf("NA\n");
				else for (auto &p:ans) printf("%s %d\n",p.cardnum.c_str(),p.score);
				break;
			}
			case 2:{
				string query;
				cin>>query;
				int num=0,totalscore=0;
				sort(arr.begin(),arr.end(),cmp2);
				int g=0;
				while (g<arr.size()&&arr[g].cardnum.substr(1,3)!=query) g++;
				for (;g<arr.size()&&arr[g].cardnum.substr(1,3)==query;g++) {
					num++;
					totalscore+=arr[g].score;
				}
				printf("Case %d: %d %s\n",i+1,type,query.c_str());
				if (num==0) printf("NA\n");
				else printf("%d %d\n",num,totalscore);
				break;
			}
			case 3:{
				vector<pair<string,int> > ans;
				unordered_map<string,int> my;
				string query;
				cin>>query;
				sort(arr.begin(),arr.end(),cmp3);
				int g=0;
				while (g<arr.size()&&arr[g].cardnum.substr(4,6)!=query) g++;
				for (;g<arr.size()&&arr[g].cardnum.substr(4,6)==query;g++)
					my[arr[g].cardnum.substr(1,3)]++;
				printf("Case %d: %d %s\n",i+1,type,query.c_str());
				if (my.size()==0) printf("NA\n");
				else {
					for (auto &p:my) ans.push_back(make_pair(p.first,p.second));
					sort(ans.begin(),ans.end(),cmpans2);
					for (auto &p:ans) printf("%s %d\n",p.first.c_str(),p.second);
				}
				break;
			}
		}
	}
	return 0;
}
