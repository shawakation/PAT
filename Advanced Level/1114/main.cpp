/*
1.并查集里面比较难的题
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> father;
unordered_set<int> tt;
unordered_map<int,int> ownM,ownarea;
struct family
{
	double totalarea,avgarea,avgM;
	int totalM,totalpeople,minid;
	family() {
		totalarea=0.0;
		totalM=totalpeople=0;
		minid=10000;
	}
};
vector<family> ans;
bool cmp(family a,family b)
{
	if (a.avgarea!=b.avgarea) return a.avgarea>b.avgarea;
	else return a.minid<b.minid;
}
unordered_map<int,family> my;
int find(int x)
{
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
void init()
{
	father.resize(10010);
	for (int k=0;k<=10000;k++) father[k]=k;
}
int main()
{
	int n;
	scanf("%d",&n);
	init();
	for (int i=0;i<n;i++) {
		int id,fatherid,motherid,k,M;
		double area;
		scanf("%d %d %d %d",&id,&fatherid,&motherid,&k);
		tt.insert(id);
		if (fatherid!=-1) {
		   unit(id,fatherid);
		   tt.insert(fatherid);
        }
		if (motherid!=-1) {
			unit(id,motherid);
			tt.insert(motherid);
		}
		for (int j=0;j<k;j++) {
			int child;
			scanf("%d",&child);
			unit(id,child);
			tt.insert(child);
		}
		scanf("%d %lf",&M,&area);
		ownM[id]=M;
		ownarea[id]=area;
	}
	for (auto &p:tt) {
		int ff=find(p);
		my[ff].totalpeople++;
		if (my[ff].minid>p) my[ff].minid=p;
		if (ownM.find(p)!=ownM.end()) my[ff].totalM+=ownM[p];
		if (ownarea.find(p)!=ownarea.end()) my[ff].totalarea+=ownarea[p];
	}
	printf("%d\n",my.size());
	for (auto &p:my) {
		p.second.avgarea=p.second.totalarea/p.second.totalpeople;
		p.second.avgM=(double)p.second.totalM/p.second.totalpeople;
		ans.push_back(p.second);
	}
	sort(ans.begin(),ans.end(),cmp);
	for (auto &p:ans)
		printf("%04d %d %.3f %.3f\n",p.minid,p.totalpeople,p.avgM,p.avgarea);
	return 0;
}
