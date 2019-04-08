#include <bits/stdc++.h>
using namespace std;
vector<int> post,in,ansf;
struct node
{
	int data,layer;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		layer=1;
		lchild=rchild=NULL;
	}
};
vector<node> ans;
node* buildtree(int postL,int postR,int inL,int inR,int lay)
{
	if (postL>postR) return NULL;
	node *t=new node(post[postR]);
	t->layer=lay;
	int k=inL;
	for (;k<=inR;k++) if (in[k]==t->data) break;
	int numL=k-inL;
	t->lchild=buildtree(postL,postL+numL-1,inL,k-1,lay+1);
	t->rchild=buildtree(postL+numL,postR-1,k+1,inR,lay+1);
	return t;
}
void layerorder(node *p)
{
	queue<node*> q;
	q.push(p);
	while (!q.empty()) {
		node *tt=q.front();
		q.pop();
		ans.push_back(*tt);
		if (tt->lchild) q.push(tt->lchild);
		if (tt->rchild) q.push(tt->rchild);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	post.resize(n);
	in.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&in[i]);
	for (int i=0;i<n;i++) scanf("%d",&post[i]);
	node *root=buildtree(0,n-1,0,n-1,1);
	layerorder(root);
	bool isleft=1;
	int i=1;
	ansf.push_back(ans[0].data);
	while (i<ans.size()) {
		int j=i+1;
		while (ans[j].layer==ans[i].layer&&j<ans.size()) j++;
		if (isleft) {
			for (int h=i;h<j;h++) ansf.push_back(ans[h].data);
			isleft=0;
		}
		else {
			for (int h=j-1;h>=i;h--) ansf.push_back(ans[h].data);
			isleft=1;
		}
		i=j;
	}
	for (int g=0;g<ansf.size();g++) {
		printf("%d",ansf[g]);
		if (g<ansf.size()-1) printf(" ");
	}
	return 0;
}
