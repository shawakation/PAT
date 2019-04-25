#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
#include <queue>
#include <stack>
#include <memory.h>
#define maxn 110
using namespace std;
struct point {
	int x,y,dis;
	point():x(0),y(0),dis(0) {}
	point(int a,int b):x(a),y(b),dis(a*a+b*b) {}
} points[maxn];
bool vis[maxn]= {0};
int num=0,m,pre[maxn];
stack<int> ans;
bool iscanfirstjump(const point &a)
{
	if (pow(a.x,2)+pow(a.y,2)<=pow(7.5+m,2)) return 1;
	else return 0;
}
bool iscanjump(const point &a,const point &b)
{
	if (pow((b.x-a.x),2)+pow((b.y-a.y),2)<=pow(m,2)) return 1;
	else return 0;
}
bool iscanescape(const point &a)
{
	if (a.x+m>=50||a.y+m>=50||a.x-m<=-50||a.y-m<=-50) return 1;
	else return 0;
}
bool cmp(const point &a,const point &b)
{
	return a.dis<b.dis;
}
void search()
{
	queue<int> q;
	int last=0,step=2;
	for (int i=0; i<num; i++)
		if (iscanfirstjump(points[i])) {
			q.push(i);
			vis[i]=1;
			last=i;
		}
	memset(pre,-1,sizeof(pre));
	while (!q.empty()) {
		int index=q.front();
		q.pop();
		if (iscanescape(points[index])) {
			while (index!=-1) {
				ans.push(index);
				index=pre[index];
			}
			printf("%d\n",step);
			while (!ans.empty()) {
				int t=ans.top();
				printf("%d %d\n",points[t].x,points[t].y);
				ans.pop();
			}
			return;
		}
		int tail=0;
		for (int h=0; h<num; h++)
			if (!vis[h]&&iscanjump(points[index],points[h])) {
				q.push(h);
				vis[h]=1;
				pre[h]=index;
				tail=h;
			}
		if (index==last) {
			step++;
			last=tail;
		}
	}
	printf("0\n");
}
int main()
{
	int n;
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (pow(a,2)+pow(b,2)<=56.25||a>=50||a<=-50||b>=50||b<=-50) continue;
		point t(a,b);
		points[num++]=t;
	}
	if (m>=42.5) {
		printf("1\n");
		return 0;
	}
	sort(points,points+num,cmp);
	search();
	return 0;
}
