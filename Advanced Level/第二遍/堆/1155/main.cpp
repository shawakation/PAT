#include <bits/stdc++.h>
#define maxn 1010
using namespace std;
int heap[maxn],n;
vector<int> path;
void search(int p)
{
	path.push_back(p);
	if (p*2>n) {
		for (int h=0;h<path.size();h++) {
			printf("%d",heap[path[h]]);
			if (h<path.size()-1) printf(" ");
		}
		printf("\n");
		path.pop_back();
		return;
	}
	if (p*2+1<=n) search(p*2+1);
	if (p*2<=n) search(p*2);
	path.pop_back();
}
bool ismaxheap()
{
	for (int h=1;h<=n/2;h++) {
		int j=h*2;
		if (j+1<=n&&heap[j+1]>heap[j]) j++;
		if (heap[j]>heap[h]) return 0;
	}
	return 1;
}
bool isminheap()
{
	for (int h=1;h<=n/2;h++) {
		int j=h*2;
		if (j+1<=n&&heap[j+1]<heap[j]) j++;
		if (heap[j]<heap[h]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&heap[i]);
	search(1);
	if (ismaxheap()) printf("Max Heap\n");
	else if (isminheap()) printf("Min Heap\n");
	else printf("Not Heap\n");
	return 0;
}
