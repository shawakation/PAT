/*
1.本题注意点在输出路径：DFS 函数开始时入栈，结束时出栈
*/
#include <bits/stdc++.h>
using namespace std;
int n=0;
vector<int> ans,heap;
void printans()
{
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
}
bool judgeMaxheap()
{
	for (int i=n/2;i>=1;i--) {
		int j=i*2;
		if (j+1<=n&&heap[j]<heap[j+1]) j++;
		if (heap[i]<heap[j]) return 0;
	}
	return 1;
}
bool judgeMinheap()
{
	for (int i=n/2;i>=1;i--) {
		int j=i*2;
		if (j+1<=n&&heap[j]>heap[j+1]) j++;
		if (heap[i]>heap[j]) return 0;
	}
	return 1;
}
void search(int k)
{
	if (k>n) return;
	ans.push_back(heap[k]);
	if (k*2>n) {
		printans();
		ans.pop_back();
		return;
	}
	if (k*2+1<=n) search(k*2+1);
	if (k*2<=n) search(k*2);
	ans.pop_back();
}
int main()
{
	scanf("%d",&n);
	heap.resize(n+1);
	for (int i=1;i<=n;i++) scanf("%d",&heap[i]);
	search(1);
	if (judgeMaxheap()) printf("Max Heap\n");
	else if (judgeMinheap()) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
