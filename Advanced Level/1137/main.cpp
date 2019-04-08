#include <bits/stdc++.h>
using namespace std;
struct student
{
	string name;
	int Gp,Gmid,Gfinal,Gtotal;
	student() {
		Gp=Gmid=Gfinal=Gtotal=-1;
	}
	friend bool operator < (const student &a,const student &b) {
		if (a.Gtotal!=b.Gtotal) return a.Gtotal>b.Gtotal;
		else return a.name<b.name;
	}
};
unordered_map<string,student> my;
vector<student> ans;
int main()
{
	int p,m,n;
	scanf("%d%d%d",&p,&m,&n);
	for (int i=0;i<p;i++) {
		string name;
		int grade;
		cin>>name;
		scanf("%d",&grade);
		if (grade>=200) my[name].Gp=grade;
	}
	for (int i=0;i<m;i++) {
		string name;
		int grade;
		cin>>name;
		scanf("%d",&grade);
		if (my.find(name)!=my.end()) my[name].Gmid=grade;
	}
	for (int i=0;i<n;i++) {
		string name;
		int grade;
		cin>>name;
		scanf("%d",&grade);
		if (my.find(name)!=my.end()) {
			if (my[name].Gmid>grade) {
				my[name].Gfinal=grade;
				my[name].Gtotal=(int)round(0.4*my[name].Gmid+0.6*my[name].Gfinal);
			}
			else my[name].Gtotal=my[name].Gfinal=grade;
			if (my[name].Gtotal>=60) {
				my[name].name=name;
				ans.push_back(my[name]);
			}
		}
	}
	sort(ans.begin(),ans.end());
	for (auto &p:ans) printf("%s %d %d %d %d\n",p.name.c_str(),p.Gp,p.Gmid,p.Gfinal,p.Gtotal);
	return 0;
}
