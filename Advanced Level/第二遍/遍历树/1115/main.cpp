#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data,layer;
	struct node *lchild,*rchild;
	node(int x,int l) {
		data=x;layer=l;
		lchild=rchild=NULL;
	}
};
int maxlayer=-1,n1=0,n2=0;
void insert(node *&p,int x,int lay)
{
	if (p==NULL) {
		p=new node(x,lay);
		maxlayer=max(maxlayer,lay);
		return;
	}
	if (x>p->data) insert(p->rchild,x,lay+1);
	else insert(p->lchild,x,lay+1);
}
void preorder(node *p)
{
	if (p==NULL) return;
	if (p->layer==maxlayer) n1++;
	else if (p->layer==maxlayer-1) n2++;
	preorder(p->lchild);
	preorder(p->rchild);
}
int main()
{
	int n;
	scanf("%d",&n);
	node *root=NULL;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		insert(root,t,1);
	}
	preorder(root);
	printf("%d + %d = %d",n1,n2,n1+n2);
	return 0;
}
