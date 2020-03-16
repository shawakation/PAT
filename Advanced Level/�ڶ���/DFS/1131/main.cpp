#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
short graph[maxn][maxn]={0};
int stationnum=0,startt,endt,minnode,mintransfer;
bool vis[maxn]={0};
unordered_map<int,int> id2num,num2id;
vector<int> temp,ans;
void convert(int id)
{
	if (id2num.find(id)==id2num.end()) {
		id2num[id]=stationnum;
		num2id[stationnum++]=id;
	}
}
int calctransfer(vector<int> &a)
{
	int curline=graph[a[0]][a[1]],transfer=0;
	for (int h=1;h<a.size()-1;h++) if (graph[a[h]][a[h+1]]!=curline) {
		curline=graph[a[h]][a[h+1]];
		transfer++;
	}
	return transfer;
}
void search(int p,int nodenum)
{
	temp.push_back(p);
	vis[p]=1;
	if (p==endt) {
		if (nodenum<minnode) {
			minnode=nodenum;
			mintransfer=calctransfer(temp);
			ans=temp;
		}
		else if (nodenum==minnode) {
			int tt=calctransfer(temp);
			if (tt<mintransfer) {
				mintransfer=tt;
				ans=temp;
			}
		}
		temp.pop_back();
		vis[p]=0;
		return;
	}
	for (int h=0;h<stationnum;h++) if (graph[p][h]>0&&vis[h]==0) search(h,nodenum+1);
	temp.pop_back();
	vis[p]=0;
}
int main()
{
	int n,k;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		int m;
		scanf("%d",&m);
		vector<int> arr(m);
		for (int j=0;j<m;j++) {
			int t;
			scanf("%d",&t);
			convert(t);
			arr[j]=id2num[t];
		}
		for (int j=0;j<m-1;j++) graph[arr[j]][arr[j+1]]=graph[arr[j+1]][arr[j]]=i;
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		scanf("%d%d",&startt,&endt);
		startt=id2num[startt];
		endt=id2num[endt];
		minnode=mintransfer=INT_MAX;
		search(startt,0);
		printf("%d\n",minnode);
		int curstop=ans[0],curline=graph[ans[0]][ans[1]];
		for (int j=1;j<ans.size()-1;j++) if (graph[ans[j]][ans[j+1]]!=curline) {
			printf("Take Line#%d from %04d to %04d.\n",curline,num2id[curstop],num2id[ans[j]]);
			curstop=ans[j];
			curline=graph[ans[j]][ans[j+1]];
		}
		printf("Take Line#%d from %04d to %04d.\n",curline,num2id[curstop],num2id[endt]);
	}
	return 0;
}
