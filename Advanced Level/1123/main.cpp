/*
1.一个点过不了。。
2.用 dfs 找最大序号判是否完全二叉树
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
int maxid=-1,n;
vector<int> ans;
int getheight(node *p)
{
	if (p==NULL) return 0;
	return p->height;
}
void updateH(node *p)
{
	p->height=max(getheight(p->lchild),getheight(p->rchild))+1;
}
int getBF(node *p)
{
	return getheight(p->lchild)-getheight(p->rchild);
}
void leftR(node *&p)
{
	node *t=p->rchild;
	p->rchild=t->lchild;
	t->lchild=p;
	updateH(t);
	updateH(p);
	p=t;
}
void rightR(node *&p)
{
	node *t=p->lchild;
	p->lchild=t->rchild;
	t->rchild=p;
	updateH(t);
	updateH(p);
	p=t;
}
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (x<p->data) {
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
	else if (x>p->data) {
		insert(p->rchild,x);
		updateH(p);
		if (getBF(p)==-2) {
			if (getBF(p->rchild)==-1) leftR(p);
			else if (getBF(p->rchild)==1) {
				rightR(p->rchild);
				leftR(p);
			}
		}
	}
}
void layerorder(node *p)
{
	queue<node*> q;
	q.push(p);
	while (!q.empty()) {
		node *t=q.front();
		q.pop();
		ans.push_back(t->data);
		if (t->lchild) q.push(t->lchild);
		if (t->rchild) q.push(t->rchild);
	}
}
void dfs(node *p,int index)
{
	if (p==NULL) return;
	maxid=max(maxid,index);
	dfs(p->lchild,index*2);
	dfs(p->rchild,index*2+1);
}
int main()
{
	scanf("%d",&n);
	node *root=NULL;
	for (int i=0;i<n;i++) {
		int w;
		scanf("%d",&w);
		insert(root,w);
	}
	layerorder(root);
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
	dfs(root,1);
	if (maxid==n) printf("YES\n");
	else printf("NO\n");
	return 0;
}
