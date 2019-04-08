/*
1.要用到 long long 时加上 typedef long long ll 简单
2.long long 会溢出，需要把这个情况考虑进去，进制转换时要判断，并且
    在判断两数大小时也要考虑
3.用给定进制数的最大数位+1作为二分开始的下界，用 ans 与 下界 的最大值+1做上界
4.超难题  1.仔细考虑变量类型和溢出
			2.二分查找
			3.防止思维定式
*/
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
//注意点一
typedef long long ll;
ll strtoll(string s)
{
	stringstream ss(s);
	ll a;
	ss>>a;
	return a;
}
ll convertTo10(string n,int radix)
{
	if (radix==10) return strtoll(n);
	else {
		ll s=0;
		int a=0;
		while (n.length()>0) {
			char cc=n[n.length()-1];
			if (isdigit(cc))
				s+=(ll)((cc-'0')*pow(radix,a));
			else if (isalpha(cc))
				s+=(ll)((10+cc-'a')*pow(radix,a));
			n.erase(n.length()-1,1);
			if (s<0) return -1;
			a++;
		}
		return s;
	}
}
//n>t-->1 n==t-->0 n<t-->-1
//注意点二：long long 的溢出问题
int cmp(string n,int radix,ll t)
{
	ll num=convertTo10(n,radix);
	if (num<0) return 1;
	else if (t>num) return -1;
	else if (t==num) return 0;
	else return 1;
}
//注意点三
//ans 初始值设定问题（卡了好久）
//没有注意到最后要加 1！细心细心再细心
int findlowest(string n)
{
	int ans=1;
	for (int i=0; i<n.length(); i++)
		if (isdigit(n[i])) ans=max(ans,n[i]-'0');
		else if (isalpha(n[i])) ans=max(ans,n[i]-'a'+10);
	return ans+1;
}
ll binarysearch(string n,ll low,ll high,ll t)
{
	ll mid;
	while (low<=high) {
		mid=(low+high)/2;
		int flag=cmp(n,mid,t);
		if (flag==0) return mid;
		else if (flag==-1) low=mid+1;
		else if (flag==1) high=mid-1;
	}
	return -1;
}
int main()
{
	string n1,n2;
	int tag,radix;
	cin>>n1>>n2>>tag>>radix;
	if (tag==2) swap(n1,n2);
	ll ans=convertTo10(n1,radix);
	ll low=findlowest(n2);
	ll high=max(low,ans)+1;
	ll oo=binarysearch(n2,low,high,ans);
	if (oo==-1) printf("Impossible");
	else printf("%lld",oo);
	return 0;
}
