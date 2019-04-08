#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
int father[maxn];
void init()
{
	for (int i=0;i<maxn;i++) father[i]=i;
}
int find(int x)
{
	int a=x;
	while (father[x]!=x) x=father[x];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa>fb) father[fa]=fb;
	else if (fa<fb) father[fb]=fa;
}
unordered_set<int> appeared;
unordered_map<int,pair<int,int> > hasestate;
struct family
{
	int smallestid,member;
	double avgset,avgarea;
	family(int id,int mem,double set,double area) {
		smallestid=id;member=mem;avgset=set;avgarea=area;
	}
	friend bool operator < (const family &a,const family &b) {
		if (a.avgarea!=b.avgarea) return a.avgarea>b.avgarea;
		else return a.smallestid<b.smallestid;
	}
};
struct tempfamily
{
	int member,totalset,totalarea;
	tempfamily() {
		member=totalset=totalarea=0;
	}
};
set<family> ans;
unordered_map<int,tempfamily> my;
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int id,dad,mom,k,sett,area;
		scanf("%d%d%d%d",&id,&dad,&mom,&k);
		if (dad!=-1) {
			unit(id,dad);
			appeared.insert(dad);
		}
		if (mom!=-1) {
			unit(id,mom);
			appeared.insert(mom);
		}
		appeared.insert(id);
		for (int j=0;j<k;j++) {
			int child;
			scanf("%d",&child);
			unit(id,child);
			appeared.insert(child);
		}
		scanf("%d%d",&sett,&area);
		hasestate[id].first=sett;
		hasestate[id].second=area;
	}
	for (auto &id:appeared) {
		my[find(id)].member++;
		if (hasestate.find(id)!=hasestate.end()) {
			my[find(id)].totalset+=hasestate[id].first;
			my[find(id)].totalarea+=hasestate[id].second;
		}
	}
	for (auto &p:my) {
		double ren=(double)p.second.member;
		double avgset=(double)p.second.totalset/ren,avgarea=(double)p.second.totalarea/ren;
		ans.insert(family(p.first,ren,avgset,avgarea));
	}
	printf("%d\n",ans.size());
	for (auto &p:ans) printf("%04d %d %.3f %.3f\n",p.smallestid,p.member,p.avgset,p.avgarea);
	return 0;
}
