#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
int father[maxn];
void init()
{
	for (int i=0;i<maxn;i++) father[i]=i;
}
int find(int p)
{
	int a=p;
	while (father[p]!=p) p=father[p];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=p;
		a=z;
	}
	return p;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
int main()
{
	init();
	int n,q,birdnum=-1;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int k,first;
		scanf("%d",&k);
		scanf("%d",&first);
		birdnum=max(birdnum,first);
		for (int j=1;j<k;j++) {
			int t;
			scanf("%d",&t);
			birdnum=max(birdnum,t);
			unit(first,t);
		}
	}
	unordered_set<int> ans;
	for (int i=1;i<=birdnum;i++) ans.insert(find(i));
	printf("%d %d\n",ans.size(),birdnum);
	scanf("%d",&q);
	for (int i=0;i<q;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (find(a)==find(b)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
