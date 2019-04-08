/*
1.一个非常致命的错误：建树时千万别忘了加上引用
2.本题正确解法是根据前序序列建二叉树，再前序遍历判断是否一样
3.vector容器比较元素是否相同可以直接用 == ，其他容器类似
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
vector<int> pre,pretest,ans;
void postorder(node *p)
{
	if (p==NULL) return;
	postorder(p->lchild);
	postorder(p->rchild);
	ans.push_back(p->data);
}
void preorder(node *p)
{
	if (p==NULL) return;
	pretest.push_back(p->data);
	preorder(p->lchild);
	preorder(p->rchild);
}
void exchange(node *p)
{
	if (p==NULL) return;
	exchange(p->lchild);
	exchange(p->rchild);
	node *tt=p->lchild;
	p->lchild=p->rchild;
	p->rchild=tt;
}
//注意点一！引用千万别忘了加，类似问题要注意
void insert(node *&root,int x)
{
	if (root==NULL) {
		root=new node(x);
		return;
	}
	if (root->data<=x) insert(root->rchild,x);
	else insert(root->lchild,x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int aa;
		scanf("%d",&aa);
		pre.push_back(aa);
	}
	node *root=NULL;
	for (int i=0; i<n; i++) insert(root,pre[i]);
	preorder(root);
	if (pre==pretest) {
		postorder(root);
		printf("YES\n");
		for (int i=0; i<ans.size(); i++) {
			printf("%d",ans[i]);
			if (i<ans.size()-1) printf(" ");
		}
	} else {
		pretest.clear();
		exchange(root);
		preorder(root);
		if (pre==pretest) {
			postorder(root);
			printf("YES\n");
			for (int i=0; i<ans.size(); i++) {
				printf("%d",ans[i]);
				if (i<ans.size()-1) printf(" ");
			}
		} else printf("NO\n");
	}
	return 0;
}
