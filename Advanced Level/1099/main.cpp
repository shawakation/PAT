/*
1.思路与 A1064 相同，只是建树方法不相同
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define maxn 110
using namespace std;
vector<int> arr;
int index=0,num=0,n;
struct node {
	int data;
	struct node *lchild,*rchild;
	node() {
		data=0;
		lchild=rchild=NULL;
	}
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
node *nodes[maxn]= {NULL};
void inorder(node *p)
{
	if (p==NULL) return;
	inorder(p->lchild);
	p->data=arr[index++];
	inorder(p->rchild);
}
void layerorder(node *root)
{
	if (root==NULL) return;
	queue<node *> q;
	q.push(root);
	while (!q.empty()) {
		node *tt=q.front();
		q.pop();
		printf("%d",tt->data);
		num++;
		if (num<n) printf(" ");
		if (tt->lchild!=NULL) q.push(tt->lchild);
		if (tt->rchild!=NULL) q.push(tt->rchild);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++) nodes[i]=new node();
	for (int i=0; i<n; i++) {
		int left,right;
		scanf("%d %d",&left,&right);
		if (left!=-1) nodes[i]->lchild=nodes[left];
		if (right!=-1) nodes[i]->rchild=nodes[right];
	}
	arr.resize(n);
	for (int i=0; i<n; i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	inorder(nodes[0]);
	layerorder(nodes[0]);
	return 0;
}
