#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned short m,n,a,b,gray;
	cin>>m>>n>>a>>b>>gray;
	short **arr=new short*[m];
	for (unsigned short i=0;i<m;i++) arr[i]=new short[n];
	for (unsigned short i=0;i<m;i++)
		for (unsigned short j=0;j<n;j++) cin>>arr[i][j];
	for (unsigned short i=0;i<m;i++)
		for (unsigned short j=0;j<n;j++)
			if (arr[i][j]>=a&&arr[i][j]<=b) arr[i][j]=(short)gray;
	for (unsigned short i=0;i<m;i++) {
		for (unsigned short j=0;j<n;j++) {
			printf("%03d",arr[i][j]);
			if (j!=n-1) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
