/*
1.关于找根节点：可以不用前序遍历每个节点的方式，而是开一个数组，将输入时出现的节点全部
                记录，遍历找第一个未出现的节点。
2.可以设一个变量记完全二叉树的最大节点标号，如果不是完全二叉树，maxid 会超过节点数 n
3.马虎了：注意到 n <= 20 因此输入节点不能用 char 来存
*/
#include <bits/stdc++.h>
#define maxn 30
using namespace std;
int n,maxid=-1,ans,nodenum=0;
struct node
{
	int id,lchild,rchild;
	node() {
		lchild=rchild=id=-1;
	}
}nodes[maxn];
void layerorder(int k)
{
	queue<int> q;
	q.push(k);
	nodes[k].id=1;
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		if (maxid<nodes[t].id) {
			maxid=nodes[t].id;
			ans=t;
		}
		if (nodes[t].lchild!=-1) {
			nodes[nodes[t].lchild].id=nodes[t].id*2;
			q.push(nodes[t].lchild);
		}
		if (nodes[t].rchild!=-1) {
			nodes[nodes[t].rchild].id=nodes[t].id*2+1;
			q.push(nodes[t].rchild);
		}
	}
}
void preorder(int p)
{
	if (p==-1) return;
	nodenum++;
	preorder(nodes[p].lchild);
	preorder(nodes[p].rchild);
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) {
		string a,b;
		cin>>a>>b;
		if (a!="-") nodes[i].lchild=strtoint(a);
		if (b!="-") nodes[i].rchild=strtoint(b);
	}
	int root=0;
	for (int i=0;i<n;i++) {
		nodenum=0;
		preorder(i);
		if (nodenum==n) {
			root=i;
			break;
		}
	}
	layerorder(root);
	if (maxid>n) {
		printf("NO %d\n",root);
		return 0;
	}
	else if (maxid==n) printf("YES %d\n",ans);
	return 0;
}
