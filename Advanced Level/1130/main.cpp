#include <bits/stdc++.h>
#define maxn 30
using namespace std;
int n=0,num=0;
string ans;
unordered_set<int> leaves;
struct node
{
	string data;
	int lchild,rchild;
	node() {
		data="";
		lchild=rchild=-1;
	}
}nodes[maxn];
void inordercount(int p)
{
	if (p==-1) return;
	inordercount(nodes[p].lchild);
	num++;
	inordercount(nodes[p].rchild);
}
void inorder(int p)
{
	if (p==-1) return;
	if (leaves.find(p)==leaves.end()) ans+="(";
	inorder(nodes[p].lchild);
	ans+=nodes[p].data;
	inorder(nodes[p].rchild);
	if (leaves.find(p)==leaves.end()) ans+=")";
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) {
		string s;
		int a,b;
		cin>>s>>a>>b;
		nodes[i].data=s;
		nodes[i].lchild=a;
		nodes[i].rchild=b;
		if (a==-1&&b==-1) leaves.insert(i);
	}
	if (n==1) {
		cout<<nodes[1].data<<endl;
		return 0;
	}
	int root;
	for (int i=1;i<=n;i++) {
		num=0;
		inordercount(i);
		if (num==n) {
			root=i;
			break;
		}
	}
	inorder(root);
	ans.erase(0,1);
	ans.erase(ans.length()-1,1);
	cout<<ans<<endl;
	return 0;
}
