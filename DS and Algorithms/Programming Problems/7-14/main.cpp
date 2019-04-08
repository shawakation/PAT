#include <bits/stdc++.h>
using namespace std;
void insertion(vector<int> &arr,int i)
{
	int tt=arr[i];
	arr.erase(arr.begin()+i);
	auto it=upper_bound(arr.begin(),arr.begin()+i,tt);
	arr.insert(it,tt);
}
void downadjust(int low,int high,vector<int> &arr)
{
	int i=low,j=i*2;
	while (j<=high) {
		if (j+1<=high&&arr[j]<arr[j+1]) j++;
		if (arr[j]>arr[i]) {
			swap(arr[j],arr[i]);
			i=j;
			j=i*2;
		}
		else break;
	}
}
void heapsort(vector<int> &arr,int i)
{
	swap(arr[1],arr[i]);
	downadjust(1,i-1,arr);
}
void createheap(vector<int> &arr,int n)
{
	for (int i=n/2;i>=1;i--) downadjust(i,n,arr);
}
void printans(vector<int> &arr,int k)
{
	for (int h=k;h<arr.size();h++) {
		printf("%d",arr[h]);
		if (h<arr.size()-1) printf(" ");
	}
	printf("\n");
}
int main()
{
	int n;
	scanf("%d",&n);
	vector<int> origin(n),change(n);
	for (int i=0;i<n;i++) scanf("%d",&origin[i]);
	for (int i=0;i<n;i++) scanf("%d",&change[i]);
	vector<int> temp=origin;
	int i=1;
	while (i<n) {
		insertion(temp,i);
		if (temp==change) break;
		i++;
	}
	if (i==n) {
		printf("Heap Sort\n");
		temp=origin;
		temp.insert(temp.begin(),0);
		change.insert(change.begin(),0);
		createheap(temp,n);
		while (i>1) {
			heapsort(temp,i--);
			if (temp==change) break;
		}
		heapsort(temp,i);
		printans(temp,1);
	}
	else {
		printf("Insertion Sort\n");
		insertion(temp,++i);
		printans(temp,0);
	}
	return 0;
}
