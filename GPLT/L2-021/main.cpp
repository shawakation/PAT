#include <bits/stdc++.h>
using namespace std;
struct person
{
	string name;
	int kind;
	double average;
	person(string _name,int _kind,double _average) {
		name=_name;kind=_kind;average=_average;
	}
	friend bool operator < (const person &a,const person &b) {
		if (a.kind!=b.kind) return a.kind>b.kind;
		else return a.average<b.average;
	}
};
vector<person> ans;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		string name;
		int k;
		cin>>name;
		scanf("%d",&k);
		unordered_set<int> my;
		for (int j=0;j<k;j++) {
			int label;
			scanf("%d",&label);
			my.insert(label);
		}
		ans.push_back(person(name,my.size(),(double)k/(double)my.size()));
	}
	sort(ans.begin(),ans.end());
	int countt=3;
	for (int i=0;i<ans.size();i++) {
		printf("%s",ans[i].name.c_str());
		countt--;
		if (countt>0) printf(" ");
		else break;
	}
	while (countt>0) {
		printf("-");
		countt--;
		if (countt>0) printf(" ");
	}
	return 0;
}
