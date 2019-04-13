#include <bits/stdc++.h>
#define maxn 110
using namespace std;
struct point {
	int x,y;
	point() {
		x=y=0;
	}
} points[maxn];
int n,m;
bool vis[maxn]= {0},isescape=0;
bool isjump(point p1,point p2)
{
	int a=pow(p1.x-p2.x,2),b=pow(p1.y-p2.y,2);
	if (a+b<=m*m) return 1;
	else return 0;
}
bool issave(point p)
{
	if (p.x+m>=50||p.x-m<=-50||p.y+m>=50||p.y-m<=-50) return 1;
	else return 0;
}
bool firstjump(point p)
{
	int a=pow(p.x,2),b=pow(p.y,2);
	if (a+b<=(m+7.5)*(m+7.5)) return 1;
	else return 0;
}
bool search(int p)
{
	vis[p]=1;
	if (issave(points[p])) isescape=1;
	for (int h=0; h<n; h++) {
		if (vis[h]==0&&isjump(points[p],points[h])) isescape=search(h);
		if (isescape) break;
	}
	return isescape;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0; i<n; i++) scanf("%d%d",&points[i].x,&points[i].y);
	if (m>=42.5) {
		printf("Yes");
		return 0;
	}
	for (int i=0; i<n; i++) {
		if (vis[i]==0&&firstjump(points[i])) {
			if (search(i)) break;
		}
	}
	if (isescape) printf("Yes");
	else printf("No");
	return 0;
}
