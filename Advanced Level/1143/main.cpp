/*
1.这个思路不好。。。写的太麻烦了。。。17分
*/
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
unordered_map<int,int> pre;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
void insert(node *&p,int x,int preid)
{
	if (p==NULL) {
		p=new node(x);
		pre[x]=preid;
		return;
	}
	if (x>p->data) insert(p->rchild,x,p->data);
	else if (x<p->data) insert(p->lchild,x,p->data);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	node *root=NULL;
	for (int i=0;i<m;i++) {
		int w;
		scanf("%d",&w);
		insert(root,w,-1);
	}
	for (int i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		bool flaga=0,flagb=0;
		if (pre.find(a)==pre.end()) flaga=1;
		if (pre.find(b)==pre.end()) flagb=1;
		if (flaga&&flagb) printf("ERROR: %d and %d are not found.\n",a,b);
		else if (flaga&&!flagb) printf("ERROR: %d is not found.\n",a);
		else if (!flaga&&flagb) printf("ERROR: %d is not found.\n",b);
		if (flaga||flagb) continue;
		flaga=flagb=0;
		vector<int> apres,bpres;
		for (int j=pre[a];j!=-1;j=pre[j]) apres.push_back(j);
		for (int j=pre[b];j!=-1;j=pre[j]) bpres.push_back(j);
		for (auto &p:apres) if (p==b) {
			flaga=1;
			break;
		}
		for (auto &p:bpres) if (p==a) {
			flagb=1;
			break;
		}
		if (flaga) {
			printf("%d is an ancestor of %d.\n",b,a);
			continue;
		}
		if (flagb) {
			printf("%d is an ancestor of %d.\n",a,b);
			continue;
		}
		flaga=flagb=0;
		for (auto &p:apres) {
			for (auto &y:bpres) {
				if (p==y) {
					printf("LCA of %d and %d is %d.\n",a,b,p);
					flaga=1;
					break;
				}
			}
			if (flaga) break;
		}
	}
	return 0;
}
