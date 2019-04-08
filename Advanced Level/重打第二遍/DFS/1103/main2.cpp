#include <bits/stdc++.h>
using namespace std;
int n,k,p,fac[30]={0},maxnum,maxfacsum=-1;
vector<int> ans,temp;
int power(int i,int p)
{
	int ans=1;
	for (int h=1;h<=p;h++) ans*=i;
	return ans;
}
int init()
{
	int f=0,tt=0;
	while (tt<=n) {
		fac[f++]=tt;
		tt=power(f,p);
	}
	return f-1;
}
void search(int index,int nownum,int sum,int facsum)
{
	if (sum==n&&nownum==k) {
		if (facsum>maxfacsum) {
			maxfacsum=facsum;
			ans=temp;
		}
		return;
	}
	if (sum>n||nownum>k) return;
	if (index>0) {
		temp.push_back(index);
		search(index,nownum+1,sum+fac[index],facsum+index);
		temp.pop_back();
		search(index-1,nownum,sum,facsum);
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&p);
	maxnum=init();
	search(maxnum,0,0,0);
	if (maxfacsum==-1) printf("Impossible");
	else {
		printf("%d = ",n);
		for (int i=0;i<ans.size();i++) {
			printf("%d^%d",ans[i],p);
			if (i<ans.size()-1) printf(" + ");
		}
	}
	return 0;
}
