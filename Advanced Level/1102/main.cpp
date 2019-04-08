/*
1.层序、中序、交换左右子树
2.注意思维，开始可以建一个指针数组保存每个节点
*/
#include <iostream>
#include <vector>
#include <queue>
#define maxn 20
using namespace std;
vector<int> layer,in;
struct node {
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
node *arr[maxn]= {NULL};
int num=0;
void preorder(node *p)
{
	if (p==NULL) return;
	num++;
	preorder(p->lchild);
	preorder(p->rchild);
}
void exchange(node *p)
{
	if (p==NULL) return;
	node *temp=p->lchild;
	p->lchild=p->rchild;
	p->rchild=temp;
	exchange(p->lchild);
	exchange(p->rchild);
}
void layerorder(node *p)
{
	queue<node *> qu;
	if (p==NULL) return;
	qu.push(p);
	while (!qu.empty()) {
		node *tt=qu.front();
		layer.push_back(tt->data);
		qu.pop();
		if (tt->lchild!=NULL) qu.push(tt->lchild);
		if (tt->rchild!=NULL) qu.push(tt->rchild);
	}
}
void inorder(node *p)
{
	if (p==NULL) return;
	inorder(p->lchild);
	in.push_back(p->data);
	inorder(p->rchild);
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	for (int i=0; i<n; i++) arr[i]=new node(i);
	for (int i=0; i<n; i++) {
		string s;
		getline(cin,s,'\n');
		if (s[0]!='-') arr[i]->lchild=arr[s[0]-'0'];
		if (s[2]!='-') arr[i]->rchild=arr[s[2]-'0'];
	}
	node *root=NULL;
	for (int i=0; i<n; i++) {
		num=0;
		preorder(arr[i]);
		if (num==n) {
			root=arr[i];
			break;
		}
	}
	exchange(root);
	layerorder(root);
	inorder(root);
	for (int i=0; i<layer.size(); i++) {
		printf("%d",layer[i]);
		if (i<layer.size()-1) printf(" ");
	}
	printf("\n");
	for (int i=0; i<in.size(); i++) {
		printf("%d",in[i]);
		if (i<in.size()-1) printf(" ");
	}
	printf("\n");
	return 0;
}
