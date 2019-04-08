/*
1.一个注意点：左旋右旋以后在调整 root 指针以前一定先更新高度
*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data,height;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;height=1;
		lchild=rchild=NULL;
	}
};
int getheight(node *p)
{
	if (p==NULL) return 0;
	return p->height;
}
int getBF(node *p)
{
	return getheight(p->lchild)-getheight(p->rchild);
}
void updateheight(node *p)
{
	if (p==NULL) return;
	p->height=max(getheight(p->lchild),getheight(p->rchild))+1;
}
void rightR(node *&p)
{
	node *t=p->lchild;
	p->lchild=t->rchild;
	t->rchild=p;
	//注意点 1
	updateheight(p);
	updateheight(t);
	p=t;
}
void leftR(node *&p)
{
	node *t=p->rchild;
	p->rchild=t->lchild;
	t->lchild=p;
	//注意点 1
	updateheight(p);
	updateheight(t);
	p=t;
}
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (p->data>x) {
		insert(p->lchild,x);
		updateheight(p);
		if (getBF(p)==2) {
			if (getBF(p->lchild)==1) rightR(p);
			else if (getBF(p->lchild)==-1) {
				leftR(p->lchild);
				rightR(p);
			}
		}
	}
	else if (p->data<x) {
		insert(p->rchild,x);
		updateheight(p);
		if (getBF(p)==-2) {
			if (getBF(p->rchild)==-1) leftR(p);
			else if (getBF(p->rchild)==1) {
				rightR(p->rchild);
				leftR(p);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	node *root=NULL;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		insert(root,t);
	}
	printf("%d",root->data);
	return 0;
}
