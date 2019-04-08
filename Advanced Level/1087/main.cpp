/*
认真认真，千万别马虎！！！！！！
*/
#include <bits/stdc++.h>
#define maxn 210
using namespace std;
const int inf=1e9;
int n=0,startt=0,endt=0,city=0,happy[maxn]={0},graph[maxn][maxn]={0},dis[maxn]={0};
int pathnum=0,maxhappy=-1,maxavghappy=-1;
bool vis[maxn]={0};
vector<int> pre[maxn],ans,tempp;
unordered_map<string,int> nametonum;
unordered_map<int,string> numtoname;
void init(string s)
{
	nametonum[s]=city;
	numtoname[city++]=s;
}
void calc(int k)
{
	fill(dis,dis+maxn,inf);
	dis[k]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=inf;
		for (int h=0;h<n;h++) if (vis[h]==0&&dis[h]<minp) {
			minp=dis[h];
			u=h;
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (graph[u][h]!=0&&vis[h]==0) {
			if (dis[h]>dis[u]+graph[u][h]) {
				dis[h]=dis[u]+graph[u][h];
				pre[h].clear();
				pre[h].push_back(u);
			}
			else if (dis[h]==dis[u]+graph[u][h]) pre[h].push_back(u);
		}
	}
}
void search(int k)
{
	tempp.push_back(k);
	if (k==startt) {
		pathnum++;
		int totalhappy=0,nodes=tempp.size()-1;
		for (int f=tempp.size()-2;f>=0;f--) totalhappy+=happy[tempp[f]];
		if (totalhappy>maxhappy) {
			maxhappy=totalhappy;
			ans=tempp;
			maxavghappy=totalhappy/nodes;
		}
		else if (totalhappy==maxhappy) {
			int avghappy=totalhappy/nodes;
			if (avghappy>maxavghappy) {
				maxavghappy=avghappy;
				ans=tempp;
			}
		}
		tempp.pop_back();
		return;
	}
	for (int h=0;h<pre[k].size();h++) search(pre[k][h]);
	tempp.pop_back();
}
int main()
{
	int k;
	string starts;
	cin>>n>>k>>starts;
	init(starts);
	startt=nametonum[starts];
	for (int i=0;i<n-1;i++) {
		string s;
		int h;
		cin>>s>>h;
		init(s);
		happy[nametonum[s]]=h;
	}
	for (int i=0;i<k;i++) {
		string a,b;
		int cost;
		cin>>a>>b>>cost;
		graph[nametonum[a]][nametonum[b]]=graph[nametonum[b]][nametonum[a]]=cost;
	}
	endt=nametonum["ROM"];
	calc(startt);
	search(endt);
	cout<<pathnum<<' '<<dis[endt]<<' '<<maxhappy<<' '<<maxavghappy<<endl;
	for (int i=ans.size()-1;i>=0;i--) {
		cout<<numtoname[ans[i]];
		if (i>0) cout<<"->";
	}
	cout<<endl;
	return 0;
}
