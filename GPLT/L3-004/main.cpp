#include <bits/stdc++.h>
using namespace std;
vector<int**> graph;
vector<bool**> vis;
int newX[]={1,-1,0,0,0,0};
int newY[]={0,0,1,-1,0,0};
int newZ[]={0,0,0,0,1,-1};
int m,n,l,t;
void init()
{
	for (int h=0;h<l;h++) {
		bool **aa=new bool*[m];
		for (int i=0;i<m;i++) aa[i]=new bool[n];
		vis.push_back(aa);
	}
	for (int i=0;i<l;i++) for (int j=0;j<m;j++) for (int h=0;h<n;h++) vis[i][j][h]=0;
}
struct point
{
	int x,y,z;
	point(int _x,int _y,int _z) {
		x=_x;y=_y;z=_z;
	}
};
bool judge(int x,int y,int z)
{
	if (x<0||x>=l||y<0||y>=m||z<0||z>=n) return 0;
	if (graph[x][y][z]==0) return 0;
	if (vis[x][y][z]) return 0;
	return 1;
}
int search(int x,int y,int z)
{
	int countt=0;
	queue<point> q;
	vis[x][y][z]=1;
	q.push(point(x,y,z));
	while (!q.empty()) {
		point p=q.front();
		q.pop();
		countt++;
		for (int h=0;h<6;h++) {
			point tt(p.x+newX[h],p.y+newY[h],p.z+newZ[h]);
			if (judge(tt.x,tt.y,tt.z)) {
				vis[tt.x][tt.y][tt.z]=1;
				q.push(tt);
			}
		}
	}
	if (countt>=t) return countt;
	else return 0;
}
int main()
{
	int total=0;
	scanf("%d%d%d%d",&m,&n,&l,&t);
 	init();
	for (int i=0;i<l;i++) {
  		int **arr=new int*[m];
		for (int j=0;j<m;j++) arr[j]=new int[n];
		for (int j=0;j<m;j++) for (int g=0;g<n;g++) scanf("%d",&arr[j][g]);
		graph.push_back(arr);
	}
	for (int i=0;i<l;i++) for (int j=0;j<m;j++) for (int g=0;g<n;g++)
		if (vis[i][j][g]==0&&graph[i][j][g]==1) total+=search(i,j,g);
	printf("%d",total);
	return 0;
}
