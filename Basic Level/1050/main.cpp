#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int N;
	cin>>N;
	int *arr=new int[N];
	for (int i=0;i<N;i++) cin>>arr[i];
	sort(arr,arr+N,cmp);
	int m=(int)sqrt(N)+1;
	int n=N/m;
	while (m*n!=N) {
		m++;
		n=N/m;
	}
	int i=0,a=0;
	int **arr2=new int *[n];
	for (int h=0;h<m;h++) arr2[h]=new int[m];
	while (a<=n-1-a&&i<N) {
		for (int aa=a;aa<n-a;aa++) arr2[a][aa]=arr[i++];
		for (int aa=a;aa<m-a;aa++) arr2[aa][n-1-a]=arr[i++];
		for (int aa=n-1-a;aa>=a;aa--) arr2[m-1-a][aa]=arr[i++];
		for (int aa=m-1-a;aa>a;aa--) arr2[aa][a]=arr[i++];
		a++;
	}
	for (int qq=0;qq<m;qq++) {
		for (int ww=0;ww<n;ww++) {
			cout<<arr2[qq][ww];
			if (ww!=n-1) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
