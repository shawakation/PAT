#include <bits/stdc++.h>
#define maxn 10010
using namespace std;
unordered_map<int,int> pre,layer;
vector<int> preseq,inseq;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;lchild=rchild=NULL;
	}
};
node* build(int preL,int preR,int inL,int inR,int _layer,int _pre)
{
	if (preL>preR) return NULL;
	node *t=new node(preseq[preL]);
	layer[t->data]=_layer;
	pre[t->data]=_pre;
	int k=inL;
	for (;k<=inR;k++) if (inseq[k]==t->data) break;
	int numL=k-inL;
	t->lchild=build(preL+1,preL+numL,inL,k-1,_layer+1,t->data);
	t->rchild=build(preL+numL+1,preR,k+1,inR,_layer+1,t->data);
	return t;
}
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	inseq.resize(n);
	for (int i=0;i<n;i++) scanf("%d",&inseq[i]);
	preseq=inseq;
	sort(inseq.begin(),inseq.end());
	node *root=build(0,n-1,0,n-1,1,INT_MIN);
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		if (layer.find(a)==layer.end()&&layer.find(b)==layer.end())
			printf("ERROR: %d and %d are not found.\n",a,b);
		else if (layer.find(a)==layer.end()||layer.find(b)==layer.end())
			printf("ERROR: %d is not found.\n",layer.find(a)==layer.end()?a:b);
		else {
			if (a==b) {
				printf("%d is an ancestor of %d.\n",a,b);
				continue;
			}
			int at=a,bt=b;
			while (layer[a]>layer[b]) a=pre[a];
			while (layer[b]>layer[a]) b=pre[b];
			if (a==b) {
				if (layer[at]>layer[bt]) printf("%d is an ancestor of %d.\n",bt,at);
				else if (layer[at]<layer[bt]) printf("%d is an ancestor of %d.\n",at,bt);
			}
			else {
				while (a!=b) {
					a=pre[a];
					b=pre[b];
				}
				printf("LCA of %d and %d is %d.\n",at,bt,a);
			}
		}
	}
	return 0;
}
