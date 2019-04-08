/*
1.本题思路：用静态数组存完全二叉树，对该树进行中序遍历，边遍历边填数
2.会写静态数组二叉树的先、中、后序遍历，注意递归边界是 root>n
3.从下标 1 开始按顺序输出的就是该完全二叉树的层次遍历
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define maxn 1010
using namespace std;
int n=0,index=0;
vector<int> arr,CBT;
void inorder(int root)
{
	if (root>n) return;
	inorder(root*2);
	CBT[root]=arr[index++];
	inorder(root*2+1);
}
int main()
{
	scanf("%d",&n);
	CBT.resize(n+1);
	arr.resize(n);
	for (int i=0; i<n; i++) scanf("%d",&arr[i]);
	sort(arr.begin(),arr.end());
	inorder(1);
	for (int i=1; i<=n; i++) {
		printf("%d",CBT[i]);
		if (i<n) printf(" ");
	}
	return 0;
}
