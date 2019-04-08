#include <bits/stdc++.h>
#define maxn 100
using namespace std;
int n,k,p,fac[maxn],maxfacsum=-1,maxnum=0;
int power(int a,int b)
{
	int ans=1;
	for (int h=0;h<b;h++) ans*=a;
	return ans;
}
void init()
{
	int tt=0;
	while (tt<=n) {
		fac[maxnum++]=tt;
		tt=power(maxnum,p);
	}
	maxnum--;
}
vector<int> ans,temp;
void printans(vector<int> &a)
{
	printf("%d = ",n);
	for (int i=0;i<a.size();i++) {
		printf("%d^%d",a[i],p);
		if (i<a.size()-1) printf(" + ");
	}
	printf("\n");
}
void search(int num,int sum,int facsum)
{
 	temp.push_back(num);
	if (temp.size()==k&&sum==n) {
		if (facsum>maxfacsum) {
			ans=temp;
			maxfacsum=facsum;
		}
  		temp.pop_back();
		return;
	}
	if (sum>n||temp.size()>k) {
	  	temp.pop_back();
	  	return;
 	}
 	//注意点：h=maxnum -> h=num 超时问题解决！
	//参考柳神的代码，剪枝牛逼！！！
	for (int h=num;h>0;h--) if (sum+fac[h]<=n) search(h,sum+fac[h],facsum+h);
 	temp.pop_back();
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	init();
	for (int i=maxnum;i>0;i--) search(i,fac[i],i);
	if (!ans.empty()) printans(ans);
	else printf("Impossible\n");
	return 0;
}
