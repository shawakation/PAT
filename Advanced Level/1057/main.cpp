/*
1.树状数组三个：lowbit getsum update
2.本题中树状数组类似于 hash 的作用，每个下标保存下标数字出现的个数
3.寻找第 k 大元素等价于找到最小的 i 使 hash[1]+hash[2]+...+hash[i]>=k 成立
    在本题中使用二分查找的方式找到最小的 i
*/
#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
stack<int> st;
int arr[maxn]={0};
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int x)
{
	int sum=0;
	for (int h=x;h>0;h-=lowbit(h)) sum+=arr[h];
	return sum;
}
void update(int x,int v)
{
	for (int h=x;h<=maxn;h+=lowbit(h)) arr[h]+=v;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char order[20]={'\0'};
		scanf("%s",order);
		if (strcmp(order,"Push")==0) {
			int t;
			scanf("%d",&t);
			st.push(t);
			update(t,1);
		}
		else if (strcmp(order,"Pop")==0) {
			if (st.empty()) printf("Invalid\n");
			else {
				printf("%d\n",st.top());
				update(st.top(),-1);
				st.pop();
			}
		}
		else {
			if (st.empty()) printf("Invalid\n");
			else {
				int kst=(st.size()&1)?((st.size()+1)/2):(st.size()/2);
				int left=1,right=maxn,mid;
				while (left<right) {
					mid=(left+right)/2;
					if (getsum(mid)>=kst) right=mid;
					else left=mid+1;
				}
				printf("%d\n",left);
			}
		}
	}
	return 0;
}
