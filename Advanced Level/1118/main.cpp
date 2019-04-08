#include <bits/stdc++.h>
using namespace std;
vector<int> father;
unordered_set<int> my,trees;
int find(int x) {
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=a;
		a=father[a];
		father[z]=x;
	}
	return x;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
void init()
{
	father.resize(10000);
	for (int k=1;k<=10000;k++) father[k]=k;
}
int main()
{
	init();
	int n,k;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int t,s;
		scanf("%d%d",&t,&s);
		my.insert(s);
		for (int j=0;j<t-1;j++) {
			int tt;
			scanf("%d",&tt);
			my.insert(tt);
			unit(s,tt);
		}
	}
	for (int i=1;i<=my.size();i++) trees.insert(find(i));
	printf("%d %d\n",trees.size(),my.size());
	scanf("%d",&k);
	for (int i=0;i<k;i++) {
		int sa,sb;
		scanf("%d %d",&sa,&sb);
		if (find(sa)==find(sb)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
