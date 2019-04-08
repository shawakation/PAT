#include <bits/stdc++.h>
#define maxn 100010
using namespace std;
int arr[maxn]={0};
int lowbit(int x)
{
	return x&(-x);
}
int getsum(int x)
{
	int sum=0;
	for (int i=x;i>0;i-=lowbit(i)) sum+=arr[i];
	return sum;
}
void update(int x,int v)
{
	for (int i=x;i<maxn;i+=lowbit(i)) arr[i]+=v;
}
stack<int> st;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char order[20];
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
		else if (strcmp(order,"PeekMedian")==0) {
			if (st.empty()) printf("Invalid\n");
			else {
				int k=(st.size()&1)?((st.size()+1)/2):(st.size()/2);
				int left=1,right=maxn,mid;
				while (left<right) {
					mid=(left+right)/2;
					if (getsum(mid)>=k) right=mid;
					else left=mid+1;
				}
				printf("%d\n",left);
			}
		}
	}
	return 0;
}
