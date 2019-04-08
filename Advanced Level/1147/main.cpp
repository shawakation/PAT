#include <bits/stdc++.h>
using namespace std;
vector<int> heap,ans;
int m=0;
bool judgeMaxheap()
{
	for (int k=m/2;k>=1;k--) {
		int g=k*2;
		if (g+1<=m&&heap[g]<heap[g+1]) g++;
		if (heap[k]<heap[g]) return 0;
	}
	return 1;
}
bool judgeMinheap()
{
	for (int k=m/2;k>=1;k--) {
		int g=k*2;
		if (g+1<=m&&heap[g]>heap[g+1]) g++;
		if (heap[k]>heap[g]) return 0;
	}
	return 1;
}
void postorder(int l)
{
	if (l>m) return;
	postorder(l*2);
	postorder(l*2+1);
	ans.push_back(heap[l]);
}
void printans()
{
	for (int i=0;i<ans.size();i++) {
		printf("%d",ans[i]);
		if (i<ans.size()-1) printf(" ");
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d%d",&n,&m);
	heap.resize(m+1);
	for (int i=0;i<n;i++) {
		heap.clear();
		ans.clear();
		for (int j=1;j<=m;j++) scanf("%d",&heap[j]);
		if (judgeMaxheap()) printf("Max Heap\n");
		else if (judgeMinheap()) printf("Min Heap\n");
		else printf("Not Heap\n");
		postorder(1);
		printans();
	}
	return 0;
}
