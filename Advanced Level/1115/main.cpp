#include <bits/stdc++.h>
using namespace std;
int n1=0,n2=0,maxlayer=1;
struct node {
	int data,layer;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (x>p->data) insert(p->rchild,x);
	else insert(p->lchild,x);
}
void layerorder(node *root)
{
	queue<node *> q;
	root->layer=1;
	q.push(root);
	while (!q.empty()) {
		node *temp=q.front();
		q.pop();
		if (temp->layer>maxlayer) maxlayer=temp->layer;
		if (temp->lchild!=NULL) {
			temp->lchild->layer=temp->layer+1;
			q.push(temp->lchild);
		}
		if (temp->rchild!=NULL) {
			temp->rchild->layer=temp->layer+1;
			q.push(temp->rchild);
		}
	}
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
	for (int i=0; i<n; i++) {
		int tt;
		scanf("%d",&tt);
		insert(root,tt);
	}
	layerorder(root);
	preorder(root);
	printf("%d + %d = %d\n",n1,n2,n1+n2);
	return 0;
}
