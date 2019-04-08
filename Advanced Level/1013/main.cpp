#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int graph[maxn][maxn]={0},city=0;
bool isvisit[maxn]={0};
vector<pair<int,int> > my;
void destory(int m)
{
	for (int k=1;k<=city;k++) {
		if (graph[m][k]==1) {
			my.push_back(make_pair(m,k));
			graph[m][k]=graph[k][m]=0;
		}
	}
}
void restore(int m)
{
	while (!my.empty()) {
		auto tt=my[my.size()-1];
		graph[tt.first][tt.second]=graph[tt.second][tt.first]=1;
		my.pop_back();
	}
	memset(isvisit,0,sizeof(isvisit));
}
void search(int p)
{
	queue<int> q;
	isvisit[p]=1;
	q.push(p);
	while (!q.empty()) {
		int topt=q.front();
		q.pop();
		for (int h=1;h<=city;h++)
			if (graph[topt][h]==1&&isvisit[h]==0) {
				isvisit[h]=1;
				q.push(h);
			}
	}
}
int main()
{
	int highway,check;
	scanf("%d%d%d",&city,&highway,&check);
	for (int i=0;i<highway;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		graph[a][b]=graph[b][a]=1;
	}
	for (int i=0;i<check;i++) {
		int t,countt=0;
		scanf("%d",&t);
		destory(t);
		for (int j=1;j<=city;j++)
			if (isvisit[j]==0) {
				countt++;
				search(j);
			}
		printf("%d\n",countt-2);
		if (i<check-1) restore(t);
	}
	return 0;
}
