/*
¡Ω¥Œ DJ+DFS£¨DJ–¥ Ï¡∑
*/
#include <bits/stdc++.h>
#define maxn 510
using namespace std;
int n,length[maxn][maxn]={0},timet[maxn][maxn]={0},dis[maxn],spend[maxn],startt,endt;
vector<int> prel[maxn],pret[maxn],tempp,ansl,anst;
int minspend=INT_MAX,minnode=INT_MAX;
bool vis[maxn]={0};
void calclength(int k)
{
	fill(dis,dis+maxn,INT_MAX);
	dis[k]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=0;h<n;h++) if (dis[h]<minp&&vis[h]==0) {
			u=h;
			minp=dis[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (vis[h]==0&&length[u][h]!=0) {
			if (dis[h]>dis[u]+length[u][h]) {
				dis[h]=dis[u]+length[u][h];
				prel[h].clear();
				prel[h].push_back(u);
			}
			else if (dis[h]==dis[u]+length[u][h]) prel[h].push_back(u);
		}
	}
}
void calctime(int k)
{
	fill(spend,spend+maxn,INT_MAX);
	spend[k]=0;
	for (int y=0;y<n;y++) {
		int u=-1,minp=INT_MAX;
		for (int h=0;h<n;h++) if (spend[h]<minp&&vis[h]==0) {
			u=h;
			minp=spend[h];
		}
		if (u==-1) return;
		vis[u]=1;
		for (int h=0;h<n;h++) if (vis[h]==0&&timet[u][h]!=0) {
			if (spend[h]>spend[u]+timet[u][h]) {
				spend[h]=spend[u]+timet[u][h];
				pret[h].clear();
				pret[h].push_back(u);
			}
			else if (spend[h]==spend[u]+timet[u][h]) pret[h].push_back(u);
		}
	}
}
void searcht(int k,int nodenum)
{
	tempp.push_back(k);
	if (k==startt) {
		if (nodenum<minnode) {
			minnode=nodenum;
			anst=tempp;
		}
		tempp.pop_back();
		return;
	}
	for (int h=0;h<pret[k].size();h++) searcht(pret[k][h],nodenum+1);
	tempp.pop_back();
}
void searchl(int k,int cost)
{
	tempp.push_back(k);
	if (k==startt) {
		if (cost<minspend) {
			minspend=cost;
			ansl=tempp;
		}
		tempp.pop_back();
		return;
	}
	for (int h=0;h<prel[k].size();h++) searchl(prel[k][h],cost+timet[prel[k][h]][k]);
	tempp.pop_back();
}
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++) {
		int v1,v2,one,l,t;
		scanf("%d %d %d %d %d",&v1,&v2,&one,&l,&t);
		if (one==1) {
			length[v1][v2]=l;
			timet[v1][v2]=t;
		}
		else {
			length[v1][v2]=length[v2][v1]=l;
			timet[v1][v2]=timet[v2][v1]=t;
		}
	}
	scanf("%d %d",&startt,&endt);
	calclength(startt);
	searchl(endt,0);
	memset(vis,0,sizeof(vis));
	tempp.clear();
	calctime(startt);
	searcht(endt,0);
	if (ansl==anst) {
		printf("Distance = %d; Time = %d: ",dis[endt],spend[endt]);
		for (int g=ansl.size()-1;g>=0;g--) {
			printf("%d",ansl[g]);
			if (g>0) printf(" -> ");
		}
		printf("\n");
	}
	else {
		printf("Distance = %d: ",dis[endt]);
		for (int g=ansl.size()-1;g>=0;g--) {
			printf("%d",ansl[g]);
			if (g>0) printf(" -> ");
		}
		printf("\n");
		printf("Time = %d: ",spend[endt]);
		for (int g=anst.size()-1;g>=0;g--) {
			printf("%d",anst[g]);
			if (g>0) printf(" -> ");
		}
		printf("\n");
	}
	return 0;
}
