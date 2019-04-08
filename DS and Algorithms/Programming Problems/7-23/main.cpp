#include <bits/stdc++.h>
using namespace std;
string in,pre;
int maxlayer=-1;
struct node
{
	char data;
	struct node *lchild,*rchild;
	node(char x) {
		data=x;
		lchild=rchild=NULL;
	}
};
node *build(int preL,int preR,int inL,int inR,int lay)
{
	if (preL>preR) return NULL;
	node *t=new node(pre[preL]);
	maxlayer=max(maxlayer,lay);
	int k=inL;
	for (;k<=inR;k++) if (in[k]==t->data) break;
	int numL=k-inL;
	t->lchild=build(preL+1,preL+numL,inL,k-1,lay+1);
	t->rchild=build(preL+numL+1,preR,k+1,inR,lay+1);
	return t;
}
int main()
{
	int n;
	scanf("%d",&n);
	cin>>pre>>in;
	node *root=build(0,n-1,0,n-1,1);
	printf("%d",maxlayer);
	return 0;
}
