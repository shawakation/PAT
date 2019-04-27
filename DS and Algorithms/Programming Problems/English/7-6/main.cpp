#include <bits/stdc++.h>
using namespace std;
struct node {
	int data,height;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		height=1;
		lchild=rchild=NULL;
	}
};
int getH(node *p)
{
	if (p==NULL) return 0;
	else return p->height;
}
int getBF(node *p)
{
	return getH(p->lchild)-getH(p->rchild);
}
void updateH(node *p)
{
	p->height=max(getH(p->lchild),getH(p->rchild))+1;
}
void leftR(node *&p)
{
	node *t=p->rchild;
	p->rchild=t->lchild;
	t->lchild=p;
	updateH(p);
	updateH(t);
	p=t;
}
void rightR(node *&p)
{
	node *t=p->lchild;
	p->lchild=t->rchild;
	t->rchild=p;
	updateH(p);
	updateH(t);
	p=t;
}
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (x>p->data) {
		insert(p->rchild,x);
		updateH(p);
		if (getBF(p)==-2) {
			if (getBF(p->rchild)==-1) leftR(p);
			else if (getBF(p->rchild)==1) {
				rightR(p->rchild);
				leftR(p);
			}
		}
	} else if (x<p->data) {
		insert(p->lchild,x);
		updateH(p);
		if (getBF(p)==2) {
			if (getBF(p->lchild)==1) rightR(p);
			else if (getBF(p->lchild)==-1) {
				leftR(p->lchild);
				rightR(p);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node *root=NULL;
	for (int i=0; i<n; i++) {
		int t;
		scanf("%d",&t);
		insert(root,t);
	}
	printf("%d",root->data);
	return 0;
}
