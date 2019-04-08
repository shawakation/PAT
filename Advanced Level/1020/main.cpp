/*
1.会写根据前、后序和中序建树的代码
2.层次遍历的代码
*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n=0;
vector<int> post,inorder,ans;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
node* buildtree(int postL,int postR,int inL,int inR)
{
	if (postL>postR) return NULL;
	node *nodee=new node(post[postR]);
	int k=inL;
	for (;k<=inR;k++)
		if (inorder[k]==nodee->data) break;
	int numL=k-inL;
	nodee->lchild=buildtree(postL,postL+numL-1,inL,k-1);
	nodee->rchild=buildtree(postL+numL,postR-1,k+1,inR);
	return nodee;
}
void layerorder(node *p)
{
	if (p==NULL) return;
	deque<node *> que;
	que.push_back(p);
	while (!que.empty()) {
		node *tt=que.front();
		ans.push_back(tt->data);
		que.pop_front();
		if (tt->lchild!=NULL) que.push_back(tt->lchild);
		if (tt->rchild!=NULL) que.push_back(tt->rchild);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		post.push_back(a);
	}
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		inorder.push_back(a);
	}
	node *root=buildtree(0,n-1,0,n-1);
	layerorder(root);
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
	return 0;
}
