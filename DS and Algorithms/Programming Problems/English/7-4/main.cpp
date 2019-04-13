#include <bits/stdc++.h>
using namespace std;
bool ishave[15]={0};
struct node
{
	int lchild,rchild;
	node() {
		lchild=rchild=-1;
	}
}nodes[15];
vector<int> ans;
void layerorder(int k)
{
	queue<int> q;
	q.push(k);
	while (!q.empty()) {
		int t=q.front();
		q.pop();
		if (nodes[t].lchild==-1&&nodes[t].rchild==-1) ans.push_back(t);
		if (nodes[t].lchild!=-1) q.push(nodes[t].lchild);
		if (nodes[t].rchild!=-1) q.push(nodes[t].rchild);
	}
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		string s;
		getline(cin,s,'\n');
		if (s[0]!='-') {
			nodes[i].lchild=s[0]-'0';
			ishave[s[0]-'0']=1;
		}
		if (s[2]!='-') {
			nodes[i].rchild=s[2]-'0';
			ishave[s[2]-'0']=1;
		}
	}
	int root=0;
	while (ishave[root]) root++;
	layerorder(root);
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	return 0;
}
