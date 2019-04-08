#include <bits/stdc++.h>
using namespace std;
vector<int> pre,in;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;lchild=rchild=NULL;
	}
};
node* build(int preL,int preR,int inL,int inR)
{
	if (preL>preR) return NULL;
	node *t=new node(pre[preL]);
	int k=inL;
	for (;k<=inR;k++) if (in[k]==t->data) break;
	int numL=k-inL;
	t->lchild=build(preL+1,preL+numL,inL,k-1);
	t->rchild=build(preL+numL+1,preR,k+1,inR);
	return t;
}
void postorder(node *p)
{
	if (p==NULL) return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%d",p->data);
	exit(0);
}
int main()
{
	int n;
	scanf("%d",&n);
	pre.resize(n);
	in.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&pre[i]);
	for (int i=0;i<n;i++) scanf("%d",&in[i]);
	node *root=build(0,n-1,0,n-1);
	postorder(root);
	return 0;
}
