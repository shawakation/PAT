#include <bits/stdc++.h>
#define maxn 505
using namespace std;
struct edge {
	int c1,c2,cost;
	edge(int a,int b,int c):c1(a),c2(b),cost(c) {}
};
int n,cost[maxn]= {0},father[maxn];
vector<edge> uses,destory;
int Find(int x)
{
	if(x==father[x]) return x;
	father[x]=Find(father[x]);
	return father[x];
}
int countSet()
{
	int num=0;
	for(int i=1; i<=n; i++) if(i==father[i]) num++;
	return num;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	while(m--) {
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(d==0) destory.push_back(edge(a,b,c));
		else uses.push_back(edge(a,b,c));
	}
	sort(destory.begin(),destory.end(),[](const edge &a,const edge &b) {
		return a.cost<b.cost;
	});
	for(int i=1; i<=n; i++) {
		iota(father,father+n+1,0);
		for(edge& p:uses) if(p.c1!=i&&p.c2!=i) {
				int fx=Find(p.c1),fy=Find(p.c2);
				if(fx!=fy) father[fx]=fy;
			}
		for(edge& p:destory) if(p.c1!=i&&p.c2!=i) {
				int fx=Find(p.c1),fy=Find(p.c2);
				if(fx!=fy) {
					father[fx]=fy;
					cost[i]+=p.cost;
				}
			}
		if(countSet()>2) cost[i]=INT_MAX;
	}
	int maxcost=0;
	vector<int> ans;
	for(int i=1; i<=n; i++) {
		if(cost[i]>0) {
			if(cost[i]>maxcost) {
				maxcost=cost[i];
				ans.clear();
				ans.push_back(i);
			} else if(cost[i]==maxcost) ans.push_back(i);
		}
	}
	if(ans.empty()) puts("0");
	else {
		if(ans.size()>1) sort(ans.begin(),ans.end());
		for(int j=0; j<ans.size(); j++) {
			printf("%d",ans[j]);
			if(j<ans.size()-1) printf(" ");
		}
		puts("");
	}
	return 0;
}
