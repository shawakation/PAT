/*
1.中序非递归遍历入栈的次序就是二叉树先序遍历序列，出栈的次序就是中序遍历的序列
2.本题其实就是根据先序和中序重建二叉树
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
vector<int> arr,preorder,inorder;
int value[50]= {0};
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
node* buildtree(int preL,int preR,int inL,int inR)
{
	if (preL>preR) return NULL;
	node *q=new node(preorder[preL]);
	int k=inL;
	for (; k<=inR; k++) if (inorder[k]==q->data) break;
	int numL=k-inL;
	q->lchild=buildtree(preL+1,numL+preL,inL,k-1);
	q->rchild=buildtree(numL+preL+1,preR,k+1,inR);
	return q;
}
void postorder(node *a)
{
	if (a==NULL) return;
	postorder(a->lchild);
	postorder(a->rchild);
	arr.push_back(value[a->data]);
}
int main()
{
	int n,key=1;
	cin>>n;
	cin.ignore();
	stack<int> my;
	for (int i=0; i<2*n; i++) {
		string s;
		getline(cin,s,'\n');
		if (s=="Pop") {
			inorder.push_back(my.top());
			my.pop();
		} else {
			value[key]=s[5]-'0';
			preorder.push_back(key);
			my.push(key);
			key++;
		}
	}
	node *root=buildtree(0,n-1,0,n-1);
	postorder(root);
	for (int i=0; i<arr.size(); i++) {
		printf("%d",arr[i]);
		if (i<arr.size()-1) printf(" ");
	}
	return 0;
}
