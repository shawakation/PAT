#include <bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *lchild,*rchild;
	node(int x) {
		data=x;
		lchild=rchild=NULL;
	}
};
unordered_map<int,int> pre,lchilds,rchilds,layer;
unordered_set<int> ishave;
void insert(node *&p,int x)
{
	if (p==NULL) {
		p=new node(x);
		return;
	}
	if (p->data>x) insert(p->lchild,x);
	else insert(p->rchild,x);
}
void preorder(node *p,int lay,int qian)
{
	if (p==NULL) return;
	layer[p->data]=lay;
	pre[p->data]=qian;
	if (p->lchild!=NULL) lchilds[p->data]=p->lchild->data;
	if (p->rchild!=NULL) rchilds[p->data]=p->rchild->data;
	preorder(p->lchild,lay+1,p->data);
	preorder(p->rchild,lay+1,p->data);
}
bool check1(int a,int b)
{
	if (ishave.find(a)==ishave.end()||ishave.find(b)==ishave.end()) return 0;
	else return 1;
}
bool check2(int a,int b)
{
	if (!check1(a,b)) return 0;
	if (pre[a]==pre[b]) return 1;
	else return 0;
}
bool check3(int a,int b)
{
	if (!check1(a,b)) return 0;
	if (pre[b]==a) return 1;
	else return 0;
}
bool check4(int a,int b)
{
	if (!check1(a,b)) return 0;
	if (lchilds[b]==a) return 1;
	else return 0;
}
bool check5(int a,int b)
{
	if (!check1(a,b)) return 0;
	if (rchilds[b]==a) return 1;
	else return 0;
}
bool check6(int a,int b)
{
	if (!check1(a,b)) return 0;
	if (layer[a]==layer[b]) return 1;
	else return 0;
}
int searchnum(string s)
{
	bool isfu=0;
	int b=0;
	for (int h=0;h<s.length();h++) {
		if (s[h]=='-') isfu=1;
		if (isdigit(s[h])) b=b*10+s[h]-'0';
	}
	if (isfu) b=-b;
	return b;
}
int main()
{
	int n,m;
	scanf("%d",&n);
	node *root=NULL;
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		insert(root,t);
		ishave.insert(t);
	}
	preorder(root,1,-1);
	scanf("%d",&m);
	cin.clear();
	cin.sync();
	for (int i=0;i<m;i++) {
		string s;
		int a;
		cin>>a;
		cin.ignore();
		getline(cin,s,'\n');
		if (s.find("root")!=string::npos) {
			if (a==root->data) printf("Yes\n");
			else printf("No\n");
		}
		else if (s.find("siblings")!=string::npos) {
			int b=searchnum(s);
			if (check2(a,b)) printf("Yes\n");
			else printf("No\n");
		}
		else if (s.find("parent")!=string::npos) {
			int b=searchnum(s);
			if (check3(a,b)) printf("Yes\n");
			else printf("No\n");
		}
		else if (s.find("left child")!=string::npos) {
			int b=searchnum(s);
			if (check4(a,b)) printf("Yes\n");
			else printf("No\n");
		}
		else if (s.find("right child")!=string::npos) {
			int b=searchnum(s);
			if (check5(a,b)) printf("Yes\n");
			else printf("No\n");
		}
		else if (s.find("level")!=string::npos) {
			int b=searchnum(s);
			if (check6(a,b)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
