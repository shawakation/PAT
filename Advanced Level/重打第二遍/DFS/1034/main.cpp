#include <bits/stdc++.h>
#define maxn 2010
using namespace std;
int k,personnum=0,maxcalltime,head,totaltime,ren;
short graph[maxn][maxn]={0},calltime[maxn]={0};
bool visren[maxn]={0};
unordered_map<string,int> idtonum;
unordered_map<int,string> numtoid;
void change(string s)
{
	if (idtonum.find(s)==idtonum.end()) {
		idtonum[s]=personnum;
		numtoid[personnum++]=s;
	}
}
void search(int k)
{
	if (visren[k]==0) {
		if (calltime[k]>maxcalltime) {
			maxcalltime=calltime[k];
			head=k;
		}
		visren[k]=1;
		ren++;
	}
	for (int h=0;h<personnum;h++) if (graph[k][h]!=0) {
		totaltime+=graph[k][h];
		graph[k][h]=graph[h][k]=0;
		search(h);
	}
}
struct gang
{
	int peoplenum,headid;
	gang(int num,int head) {
		peoplenum=num;headid=head;
	}
	friend bool operator < (const gang &a,const gang &b) {
		return numtoid[a.headid]<numtoid[b.headid];
	}
};
set<gang> ans;
int main()
{
	int n;
	cin>>n>>k;
	for (int i=0;i<n;i++) {
		string a,b;
		int c;
		cin>>a>>b>>c;
		change(a);
		change(b);
		graph[idtonum[a]][idtonum[b]]+=c;
		graph[idtonum[b]][idtonum[a]]+=c;
		calltime[idtonum[a]]+=c;
		calltime[idtonum[b]]+=c;
	}
	for (int i=0;i<personnum;i++) if (visren[i]==0) {
		maxcalltime=-1,head=-1,totaltime=0,ren=0;
		search(i);
		if (totaltime>k&&ren>2) ans.insert(gang(ren,head));
	}
	printf("%d\n",ans.size());
	for (auto &p:ans) printf("%s %d\n",numtoid[p.headid].c_str(),p.peoplenum);
	return 0;
}
