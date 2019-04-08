#include <bits/stdc++.h>
#define maxn 210
using namespace std;
int n,city=0,startt,endt,graph[maxn][maxn]={0},enemy[maxn],dis[maxn],pathnum=0,maxcity=-1;
int maxkill=-1;
bool vis[maxn]={0};
vector<int> pre[maxn],temp,ans;
unordered_map<string,int> strtonum;
unordered_map<int,string> numtostr;
void convert(string s)
{
	if (strtonum.find(s)==strtonum.end()) {
		strtonum[s]=city;
		numtostr[city++]=s;
	}
}
void calc(int p)
{
	fill(dis,dis+maxn,INT_MAX);
	dis[p]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=0;h<n;h++) if (vis[h]==0&&dis[h]<minp) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (graph[u][h]>0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int p,int killnum,int citynum)
{
	temp.push_back(p);
	if (p==startt) {
		pathnum++;
		if (citynum>maxcity) {
			maxcity=citynum;
			maxkill=killnum;
			ans=temp;
		}
		else if (citynum==maxcity) {
			if (killnum>maxkill) {
				maxkill=killnum;
				ans=temp;
			}
		}
		temp.pop_back();
		return;
	}
	for (int h=0;h<pre[p].size();h++) search(pre[p][h],killnum+enemy[pre[p][h]],citynum+1);
	temp.pop_back();
}
int main()
{
	int k;
	string starts,ends;
	scanf("%d%d",&n,&k);
	cin>>starts>>ends;
	convert(starts);
	convert(ends);
	startt=strtonum[starts];
	endt=strtonum[ends];
	for (int i=0;i<n-1;i++) {
		string s;
		int e;
		cin>>s;
		scanf("%d",&e);
		convert(s);
		enemy[strtonum[s]]=e;
	}
	for (int i=0;i<k;i++) {
		string a,b;
		int c;
		cin>>a>>b;
		scanf("%d",&c);
		graph[strtonum[a]][strtonum[b]]=graph[strtonum[b]][strtonum[a]]=c;
	}
	calc(startt);
	search(endt,enemy[endt],0);
	for (int i=ans.size()-1;i>=0;i--) {
		printf("%s",numtostr[ans[i]].c_str());
		if (i>0) printf("->");
	}
	printf("\n%d %d %d",pathnum,dis[endt],maxkill);
	return 0;
}
