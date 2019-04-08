/*
1.更优解：给出了 BST 树的前序，从逻辑上考虑，a 和 b 的最低公共祖先就是
			前序序列中在 a 与 b 之间的数 c,因为 a 和 b 肯定分别在左子树或右子树上
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	vector<int> arr(n);
	unordered_map<int,bool> my;
	for (int i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		my[arr[i]]=1;
	}
	for (int i=0;i<m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		int k=0;
		for (;k<n;k++) if (u>=arr[k]&&v<=arr[k]||u<=arr[k]&&v>=arr[k]) break;
		if (my[u]==0&&my[v]==0) printf("ERROR: %d and %d are not found.\n",u,v);
		else if (my[u]==0||my[v]==0)
			printf("ERROR: %d is not found.\n",my[u]?v:u);
		else if (arr[k]==u||arr[k]==v)
			printf("%d is an ancestor of %d.\n",arr[k],arr[k]==u?v:u);
		else printf("LCA of %d and %d is %d.\n",u,v,arr[k]);
	}
	return 0;
}
