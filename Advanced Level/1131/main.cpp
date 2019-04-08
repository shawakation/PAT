/*
1.注意点：复杂图的 dfs 函数，回溯时把访问标记位也回溯掉，否则找到的不是最佳。
2.dfs 的缺点：超时问题。。。。
*/
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
int stationnum=1,graph[maxn][maxn]={0},startt,endt,minstation,mintransfer;
vector<int> path,ans;
bool vis[maxn];
unordered_map<string,int> numtoid;
unordered_map<int,string> idtonum;
void convert(string s)
{
	if (numtoid.find(s)==numtoid.end()) {
		numtoid[s]=stationnum;
		idtonum[stationnum++]=s;
	}
}
int calctransfer(vector<int> &arr)
{
	int curline,transfer=0;
	for (int i=0;i<arr.size()-1;i++) {
		if (i==0) curline=graph[arr[i]][arr[i+1]];
		else {
			if (graph[arr[i]][arr[i+1]]!=curline) {
				curline=graph[arr[i]][arr[i+1]];
				transfer++;
			}
		}
	}
	return transfer;
}
void search(int p)
{
	path.push_back(p);
 	vis[p]=1;
	if (p==endt) {
		int transfers=calctransfer(path);
		if (path.size()<minstation) {
			minstation=path.size();
			mintransfer=transfers;
			ans=path;
		}
		else if (path.size()==minstation) {
			if (transfers<mintransfer) {
				mintransfer=transfers;
				ans=path;
			}
		}
		path.pop_back();
		//注意点：除了出栈外把标记位也去掉
		vis[p]=0;
		return;
	}
	for (int h=1;h<=stationnum;h++) if (graph[p][h]!=0&&vis[h]==0) search(h);
	path.pop_back();
	//注意点
	vis[p]=0;
}
int main()
{
	int n,query;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int num;
		scanf("%d",&num);
		vector<int> arr(num);
		for (int j=0;j<num;j++) {
			string station;
			cin>>station;
			convert(station);
			arr[j]=numtoid[station];
		}
		for (int j=0;j<num-1;j++) graph[arr[j]][arr[j+1]]=graph[arr[j+1]][arr[j]]=i;
	}
	scanf("%d",&query);
	for (int i=0;i<query;i++) {
		string starts,ends;
		cin>>starts>>ends;
		startt=numtoid[starts];
		endt=numtoid[ends];
		minstation=mintransfer=INT_MAX;
  		memset(vis,0,sizeof(vis));
		ans.clear();
		search(startt);
		int curstation,curlines;
		printf("%d\n",minstation-1);
		for (int f=0;f<ans.size()-1;f++) {
			if (f==0) {
				curlines=graph[ans[f]][ans[f+1]];
				curstation=ans[f];
			}
			else {
				if (graph[ans[f]][ans[f+1]]!=curlines) {
					printf("Take Line#%d from %s to %s.\n",curlines,idtonum[curstation].c_str(),idtonum[ans[f]].c_str());
					curlines=graph[ans[f]][ans[f+1]];
					curstation=ans[f];
				}
			}
		}
		printf("Take Line#%d from %s to %s.\n",curlines,idtonum[curstation].c_str(),idtonum[endt].c_str());
	}
	return 0;
}
