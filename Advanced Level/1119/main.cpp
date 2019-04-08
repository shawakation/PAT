#include <bits/stdc++.h>
using namespace std;
vector<int> pre,post,ans;
bool flag=1;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
void printans()
{
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
}
node* build(int preL,int preR,int postL,int postR)
{
	if (preL>preR) return NULL;
	node *t=new node(pre[preL]);
	if (preL==preR) return t;
	int k=preL+1;
	for (;k<=preR;k++) if (pre[k]==post[postR-1]) break;
	if (k-preL>1) {
		t->lchild=build(preL+1,k-1,postL,postL+k-preL-2);
		t->rchild=build(k,preR,postL+k-preL-1,postR-1);
	}
	else {
		flag=0;
		t->lchild=build(k,preR,postL+k-preL-1,postR-1);
	}
	return t;
}
void inorder(node *p)
{
	if (p==NULL) return;
	inorder(p->lchild);
	ans.push_back(p->data);
	inorder(p->rchild);
}
int main()
{
	int n;
	scanf("%d",&n);
	pre.resize(n);
	post.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&pre[i]);
	for (int i=0;i<n;i++) scanf("%d",&post[i]);
	node *root=build(0,n-1,0,n-1);
	inorder(root);
	if (flag) printf("Yes\n");
	else printf("No\n");
	printans();
	return 0;
}
