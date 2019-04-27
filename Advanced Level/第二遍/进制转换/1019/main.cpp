#include <bits/stdc++.h>
using namespace std;
bool ispara(const vector<long> &arr)
{
	int len=arr.size();
	for (int i=0;i<=len/2-1;i++) if (arr[i]!=arr[len-1-i]) return 0;
	return 1;
}
int main()
{
	long n,b;
	scanf("%ld%ld",&n,&b);
	vector<long> convert;
	do {
		long remander=n%b;
		convert.push_back(remander);
		n/=b;
	} while (n!=0);
	if (ispara(convert)) printf("Yes\n");
	else printf("No\n");
	for (int i=convert.size()-1;i>=0;i--) {
		printf("%d",convert[i]);
		if (i>0) printf(" ");
	}
	printf("\n");
	return 0;
}
