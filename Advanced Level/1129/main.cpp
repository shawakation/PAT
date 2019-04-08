/*
1.set 存结构体时的排序，重载 < 号，排序规则与 sort 中的 cmp 相同
2.set 重载完 < 号即可使用 find ，但注意当结构体中所有都一样时才查找成功
*/
#include <bits/stdc++.h>
#define maxn 50010
using namespace std;
struct node
{
	int id,f;
	node(int _id,int _f) {
		id=_id;f=_f;
	}
	friend bool operator < (const node &a,const node &b) {
		if (a.f!=b.f) return a.f>b.f;
		else return a.id<b.id;
	}
};
int cnt[maxn]={0};
int main()
{
	int n,k;
	set<node> my;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		int t;
		scanf("%d",&t);
		if (my.size()>0) {
			printf("%d:",t);
			int s=k;
			for (auto &p:my) {
				printf(" %d",p.id);
				s--;
				if (s==0) break;
			}
			printf("\n");
		}
		auto it=my.find(node(t,cnt[t]));
		if (it!=my.end()) my.erase(it);
		cnt[t]++;
		my.insert(node(t,cnt[t]));
	}
	return 0;
}
