#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	bool isrb;  //1->red 0->black
	struct node *lchild,*rchild;
	node(int x,bool rb) {
		data=x;isrb=rb;
		lchild=rchild=NULL;
	}
};
int blacknum;
bool _isrb;
void insert(node *&p,int x)
{
	if (p==NULL) {
		if (x>0) p=new node(x,0);
		else p=new node(abs(x),1);
		return;
	}
	if (abs(x)>p->data) insert(p->rchild,x);
	else insert(p->lchild,x);
}
bool judge1(node *p)
{
	if (p==NULL) return 1;
	if (p->isrb) {
		if (p->lchild!=NULL&&p->lchild->isrb) return 0;
		if (p->rchild!=NULL&&p->rchild->isrb) return 0;
	}
	return judge1(p->lchild)&&judge1(p->rchild);
}
void search(node *p,int blacknode)
{
	if (p==NULL) {
		blacknode++;
		if (blacknum==-1) blacknum=blacknode;
		else if (blacknode!=blacknum) _isrb=0;
		return;
	}
	if (p->isrb==0) blacknode++;
	search(p->lchild,blacknode);
	search(p->rchild,blacknode);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int m;
		scanf("%d",&m);
		node *root=NULL;
		for (int j=0;j<m;j++) {
			int t;
			scanf("%d",&t);
			insert(root,t);
		}
		if (root->isrb) printf("No\n");
		else {
			if (!judge1(root)) printf("No\n");
			else {
				blacknum=-1;
				_isrb=1;
				search(root,0);
				if (_isrb) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
