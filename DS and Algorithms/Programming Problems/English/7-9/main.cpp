#include <bits/stdc++.h>
using namespace std;
struct node {
	char data;
	int weight;
	struct node *lchild,*rchild;
	node():data('\0'),weight(0),lchild(NULL),rchild(NULL) {}
	node(char a,int b):data(a),weight(b),lchild(NULL),rchild(NULL) {}
};
struct cmp {
	bool operator () (const node *a,const node *b) const {
		return a->weight>b->weight;
	}
};
priority_queue<node*,deque<node*>,cmp> q;
node* buildtree()
{
	while (q.size()>1) {
		node *t1=q.top();
		q.pop();
		node *t2=q.top();
		q.pop();
		node *t3=new node('\0',t1->weight+t2->weight);
		t3->lchild=t1;
		t3->rchild=t2;
		q.push(t3);
	}
	return q.top();
}
int preorder(node *p,int depth)
{
	if (!(p->lchild==NULL&&p->rchild==NULL))
		return preorder(p->lchild,depth+1)+preorder(p->rchild,depth+1);
	else return depth*p->weight;
}
bool isleaf(node *p)
{
	if (p==NULL) return 0;
	if (p->lchild==NULL&&p->rchild==NULL) return 1;
	else return 0;
}
unordered_map<char,int> op;
int main()
{
	int n,m;
	cin>>n;
	for (int i=0; i<n; i++) {
		char c;
		int w;
		cin>>c>>w;
		q.push(new node(c,w));
		op[c]=w;
	}
	node *root=buildtree();
	int wpl=preorder(root,0);
	cin>>m;
	for (int i=0; i<m; i++) {
		char c;
		string code;
		int wplt=0;
		vector<pair<char,string> > ans;
		unordered_map<string,int> hasappear;
		for (int j=0; j<n; j++) {
			cin>>c>>code;
			ans.push_back(make_pair(c,code));
			hasappear[code]++;
			wplt+=op[c]*code.length();
		}
		if (wplt!=wpl) printf("No\n");
		else {
			node *tree=new node();
			bool isavail=1;
			for (auto &p:ans) {
				string t=p.second;
				node *next=tree;
				for (char c:t) {
					if (c=='0') {
						if (next->lchild==NULL) next->lchild=new node();
						next=next->lchild;
					} else if (c=='1') {
						if (next->rchild==NULL) next->rchild=new node();
						next=next->rchild;
					}
				}
				if (!isleaf(next)) {
					printf("No\n");
					isavail=0;
					break;
				} else if (hasappear[t]>1) {
					printf("No\n");
					isavail=0;
					break;
				}
			}
			if (isavail) printf("Yes\n");
		}
	}
	return 0;
}
