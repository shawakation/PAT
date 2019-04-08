/*
1.取模运算，不要写成 ans+=nump*numt%mod 因为 mod 运算不具有结合律
            要写成 ans=(ans+nump*numt)%mod
2.本题是比较难的逻辑题，注意找到规律
*/
#include <iostream>
#include <string>
using namespace std;
const int mod=1000000007;
const int maxn=100010;
int numP[maxn]={0};
int main()
{
	string s;
	getline(cin,s,'\n');
	long ans=0;
	int lens=s.length(),numT=0;
	if (s[0]=='P') numP[0]=1;
	else numP[0]=0;
	for (int i=1;i<lens;i++) {
		if (s[i]=='P') numP[i]=numP[i-1]+1;
		else numP[i]=numP[i-1];
	}
	for (int i=lens-1;i>=0;i--) {
		if (s[i]=='T') numT++;
		else if (s[i]=='A') ans=(numP[i]*numT+ans)%mod;
	}
	printf("%ld",ans);
	return 0;
}
