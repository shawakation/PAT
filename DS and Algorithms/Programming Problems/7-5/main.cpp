#include <bits/stdc++.h>
using namespace std;
int n,indext=1;
vector<int> heap;
void upadjust(int low,int high)
{
	int i=high,j=i/2;
	while (j>=low) {
		if (heap[j]>heap[i]) {
			swap(heap[i],heap[j]);
			i=j;
			j=i/2;
		}
		else break;
	}
}
void createheap(int m)
{
	heap[indext]=m;
	upadjust(1,indext++);
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	heap.resize(n+1);
	for (int i=1;i<=n;i++) {
		int t;
		scanf("%d",&t);
		createheap(t);
	}
	for (int i=0;i<m;i++) {
		int t;
		scanf("%d",&t);
		while (t>1) {
			printf("%d ",heap[t]);
			t/=2;
		}
		printf("%d\n",heap[t]);
	}
	return 0;
}
