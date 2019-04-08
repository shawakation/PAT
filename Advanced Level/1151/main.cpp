/*
1.用前序遍历来记录每个节点的深度
2.建树时用数组保存每个节点的前驱
3.简单 lca 算法：先把 a b 调到同一层上，再 a=pre[a] b=pre[b] 直到 a==b
4.本题结点值可能是负数，因此不能用数组，用 unordered_map
*/
#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
unordered_map<int,int> pre,layer;
vector<int> in,pre1;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
node* buildtree(int preL,int preR,int inL,int inR,int prior)
{
	if (preL>preR) return NULL;
	node *tt=new node(pre1[preL]);
	pre[tt->data]=prior;
	int k=inL;
	for (;k<=inR;k++) if (in[k]==tt->data) break;
	int numL=k-inL;
	tt->lchild=buildtree(preL+1,preL+numL,inL,k-1,tt->data);
	tt->rchild=buildtree(preL+numL+1,preR,k+1,inR,tt->data);
	return tt;
}
void preorder(node *p,int lay)
{
	if (p==NULL) return;
	layer[p->data]=lay;
	preorder(p->lchild,lay+1);
	preorder(p->rchild,lay+1);
}
void lca(int a,int b)
{
	int at=a,bt=b;
	while (layer[a]!=layer[b]) {
		if (layer[a]<layer[b]) b=pre[b];
		else a=pre[a];
	}
	if (a==b) {
		if (layer[at]<layer[bt]) printf("%d is an ancestor of %d.\n",at,bt);
		else printf("%d is an ancestor of %d.\n",bt,at);
		return;
	}
	while (a!=b) {
		a=pre[a];
		b=pre[b];
	}
	printf("LCA of %d and %d is %d.\n",at,bt,a);
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	pre1.resize(n);
	in.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&in[i]);
	for (int i=0;i<n;i++) scanf("%d",&pre1[i]);
	node *root=buildtree(0,n-1,0,n-1,-1);
	preorder(root,1);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (layer.find(a)==layer.end()&&layer.find(b)==layer.end())
			printf("ERROR: %d and %d are not found.\n",a,b);
		else if (layer.find(a)==layer.end()&&layer.find(b)!=layer.end())
			printf("ERROR: %d is not found.\n",a);
		else if (layer.find(a)!=layer.end()&&layer.find(b)==layer.end())
			printf("ERROR: %d is not found.\n",b);
		else lca(a,b);
	}
	return 0;
}
