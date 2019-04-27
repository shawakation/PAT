#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
int father[maxn];
void init(int n)
{
	for (int i=1; i<=n; i++) father[i]=i;
}
int find(int x)
{
	int a=x;
	while (x!=father[x]) x=father[x];
	while (a!=father[a]) {
		int z=father[a];
		father[a]=x;
		a=z;
	}
	return x;
}
void unit(int a,int b)
{
	int fa=find(a),fb=find(b);
	if (fa!=fb) father[fa]=fb;
}
unordered_set<int> ans;
int main()
{
	int n;
	cin>>n;
	init(n);
	char order;
	while (1) {
		cin>>order;
		if (order=='S') break;
		else if (order=='I') {
			int a,b;
			cin>>a>>b;
			unit(a,b);
		} else if (order=='C') {
			int a,b;
			cin>>a>>b;
			if (find(a)==find(b)) printf("yes\n");
			else printf("no\n");
		}
	}
	for (int i=1; i<=n; i++) ans.insert(find(i));
	if (ans.size()==1) printf("The network is connected.\n");
	else printf("There are %d components.\n",ans.size());
	return 0;
}
