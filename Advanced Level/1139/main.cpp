/*
1.注意点：-0000 与 0000 int 都认为是 0 ，无法判断性别，因此要用字符串存
2.dfs 超时问题。。
3.回溯的问题：把标记位要去掉，这样可以枚举所有从起点到终点的路径
*/
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
bool gender[maxn]={0},answer[4]={0},vis[maxn]={0};
unordered_set<int> graph[maxn];
vector<int> temp;
int n,startt,endt;
vector<pair<int,int> > ans;
void search(int k)
{
	temp.push_back(k);
	vis[k]=1;
	if (k==endt) {
		if (temp.size()==4) {
			bool flag=1;
			for (int h=0;h<4;h++) if (gender[temp[h]]!=answer[h]) {
				flag=0;
				break;
			}
			if (flag) ans.push_back(make_pair(temp[1],temp[2]));
		}
		temp.pop_back();
		vis[k]=0;
		return;
	}
	if (temp.size()>4) {
		temp.pop_back();
		vis[k]=0;
		return;
	}
	for (auto &p:graph[k]) if (p!=startt&&vis[p]==0) search(p);
	temp.pop_back();
	vis[k]=0;
}
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if (a.first!=b.first) return a.first<b.first;
	else return a.second<b.second;
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int main()
{
	int m,k;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		string a,b;
		int a1,b1;
		cin>>a>>b;
		if (a[0]!='-') gender[strtoint(a)]=1;
		else a.erase(0,1);
		a1=strtoint(a);
		if (b[0]!='-') gender[strtoint(b)]=1;
		else b.erase(0,1);
		b1=strtoint(b);
		graph[a1].insert(b1);
		graph[b1].insert(a1);
	}
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		string a,b;
		cin>>a>>b;
		memset(answer,0,sizeof(answer));
		if (a[0]!='-') answer[0]=answer[1]=1;
		else a.erase(0,1);
		if (b[0]!='-') answer[2]=answer[3]=1;
		else b.erase(0,1);
		ans.clear();
		startt=strtoint(a);
		endt=strtoint(b);
		search(startt);
		if (ans.size()>0) {
			sort(ans.begin(),ans.end(),cmp);
			printf("%d\n",ans.size());
			for (auto &p:ans) printf("%04d %04d\n",p.first,p.second);
		}
		else printf("%d\n",ans.size());
	}
	return 0;
}
