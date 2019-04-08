#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
vector<int> arr;
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
void postorder(node *a)
{
	if (a==NULL) return;
	postorder(a->lchild);
	postorder(a->rchild);
	arr.push_back(a->data);
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	stack<node*> my;
	node *p=NULL,*root=NULL;
	for (int i=0; i<2*n; i++) {
		string s;
		getline(cin,s,'\n');
		if (s=="Pop") {
			p=my.top();
			my.pop();
		} else {
			int num=s[5]-'0';
			if (i==0) {
				p=new node(num);
				root=p;
				my.push(p);
			} else {
				node *tt=new node(num);
				if (p->lchild==NULL) {
					p->lchild=tt;
					p=p->lchild;
				} else if (p->rchild==NULL) {
					p->rchild=tt;
					p=p->rchild;
				}
				my.push(tt);
			}
		}
	}
	postorder(root);
	for (int i=0;i<arr.size();i++) {
		printf("%d",arr[i]);
		if (i<arr.size()-1) printf(" ");
	}
	return 0;
}
