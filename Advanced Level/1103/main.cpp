/*
1.预处理思想：先把不超过 n 的 1 到 最大 k^p 存入数组
2.dfs 在该数组中选数，每个数有选、不选两种
3.注意一个数可以重复选择多次
*/
#include <bits/stdc++.h>
#define maxn 400
using namespace std;
int p=0,n=0,k=0,maxsum=-1;
vector<int> ans,fac,te;
void init()
{
	int i=0,tt=0;
	while (tt<=n) {
		fac.push_back(tt);
		tt=(int)pow(++i,p);
	}
}
void search(int index,int cur,int sum,int facsum)
{
	if (cur==k&&sum==n) {
		if (facsum>maxsum) {
			maxsum=facsum;
			ans.assign(te.begin(),te.end());
		}
		return;
	}
	if (cur>k||sum>n) return;
	if (index>0) {
		te.push_back(index);
		search(index,cur+1,sum+fac[index],facsum+index);
		te.pop_back();
		search(index-1,cur,sum,facsum);
	}
}
int main()
{
	scanf("%d %d %d",&n,&k,&p);
	init();
	search(fac.size()-1,0,0,0);
	if (maxsum!=-1) {
		printf("%d = ",n);
		for (int i=0; i<ans.size(); i++) {
			printf("%d^%d",ans[i],p);
			if (i<ans.size()-1) printf(" + ");
		}
		printf("\n");
	} else printf("Impossible\n");
	return 0;
}
