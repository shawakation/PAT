#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data,id;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
int n,maxid=-1,n1;
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (x>p->data) insert(p->lchild,x);
	else insert(p->rchild,x);
}
void layerorder(node *p)
{
	queue<node*> q;
	p->id=1;
	q.push(p);
	while (!q.empty()) {
		node *t=q.front();
		q.pop();
		maxid=max(maxid,t->id);
		n--;
		printf("%d",t->data);
		if (n>0) printf(" ");
		if (t->lchild!=NULL) {
			t->lchild->id=t->id*2;
			q.push(t->lchild);
		}
		if (t->rchild!=NULL) {
			t->rchild->id=t->id*2+1;
			q.push(t->rchild);
		}
	}
}
int main()
{
	scanf("%d",&n);
	n1=n;
	node *root=NULL;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		insert(root,t);
	}
	layerorder(root);
	printf("\n");
	if (maxid==n1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
