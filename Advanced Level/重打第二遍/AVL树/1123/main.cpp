#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data,height;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;height=1;lchild=rchild=NULL;
	}
};
int getheight(node *p)
{
	if (p==NULL) return 0;
	else return p->height;
}
int getBF(node *p)
{
	return getheight(p->lchild)-getheight(p->rchild);
}
void updateheight(node *p)
{
	p->height=max(getheight(p->lchild),getheight(p->rchild))+1;
}
void leftR(node *&p)
{
	node *t=p->rchild;
	p->rchild=t->lchild;
	t->lchild=p;
	updateheight(p);
	updateheight(t);
	p=t;
}
void rightR(node *&p)
{
	node *t=p->lchild;
	p->lchild=t->rchild;
	t->rchild=p;
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
	if (x>p->data) {
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
	else if (x<p->data) {
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
}
unordered_map<int,int> my;
int maxid=-1,n,countt;
void layerorder(node *p)
{
	queue<node*> q;
	my[p->data]=1;
	q.push(p);
	while (!q.empty()) {
		node *t=q.front();
		q.pop();
		maxid=max(maxid,my[t->data]);
		countt--;
		printf("%d",t->data);
		if (countt>0) printf(" ");
		if (t->lchild!=NULL) {
			my[t->lchild->data]=my[t->data]*2;
			q.push(t->lchild);
		}
		if (t->rchild!=NULL) {
			my[t->rchild->data]=my[t->data]*2+1;
			q.push(t->rchild);
		}
	}
}
int main()
{
	scanf("%d",&n);
	countt=n;
	node *root=NULL;
	for (int i=0;i<n;i++) {
		int w;
		scanf("%d",&w);
		insert(root,w);
	}
	layerorder(root);
	printf("\n");
	if (maxid==n) printf("YES");
	else printf("NO");
	return 0;
}
