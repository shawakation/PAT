#include <bits/stdc++.h>
using namespace std;
vector<int> arr,ans;
int n;
bool ismaxheap()
{
	for (int i=n/2;i>=1;i--) {
		int j=i*2;
		if (j+1<=n&&arr[j]<arr[j+1]) j++;
		if (arr[i]<arr[j]) return 0;
	}
	return 1;
}
bool isminheap()
{
	for (int i=n/2;i>=1;i--) {
		int j=i*2;
		if (j+1<=n&&arr[j+1]<arr[j]) j++;
		if (arr[i]>arr[j]) return 0;
	}
	return 1;
}
void postorder(int k)
{
	if (k>n) return;
	postorder(k*2);
	postorder(k*2+1);
	ans.push_back(arr[k]);
}
void printans()
{
	for (int h=0;h<ans.size();h++) {
		printf("%d",ans[h]);
		if (h<ans.size()-1) printf(" ");
	}
	printf("\n");
}
int main()
{
	int m;
	scanf("%d%d",&m,&n);
	arr.resize(n+1);
	for (int i=0;i<m;i++) {
		arr.clear();
		ans.clear();
		for (int j=1;j<=n;j++) scanf("%d",&arr[j]);
		if (ismaxheap()) printf("Max Heap\n");
		else if (isminheap()) printf("Min Heap\n");
		else printf("Not Heap\n");
		postorder(1);
		printans();
	}
	return 0;
}
