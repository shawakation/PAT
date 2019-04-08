/*
1.陷阱一：样例中有无效节点的情况，只输出有效节点即可
2.陷阱二：没有有效节点，应该输出 “0 -1\n”
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
	int addr,data,next;
	node() {
		addr=data=next=0;
	}
};
bool cmp(node &a,node &b)
{
	return a.data<b.data;
}
int main()
{
	int n,startaddr;
	scanf("%d %d",&n,&startaddr);
	unordered_map<int,node> my;
	for (int i=0; i<n; i++) {
		node tt;
		scanf("%d %d %d",&tt.addr,&tt.data,&tt.next);
		my[tt.addr]=tt;
	}
	vector<node> arr;
	for (int p=startaddr; p!=-1; p=my[p].next) arr.push_back(my[p]);
	sort(arr.begin(),arr.end(),cmp);
	for (int p=0; p<arr.size(); p++) {
		if (p<arr.size()-1) arr[p].next=arr[p+1].addr;
		else arr[p].next=-1;
	}
	if (arr.size()>0) printf("%d %05d\n",arr.size(),arr[0].addr);
	else {
		printf("0 -1\n");
		return 0;
	}
	for (auto &p:arr) {
		printf("%05d %d ",p.addr,p.data);
		if (p.next!=-1) printf("%05d\n",p.next);
		else printf("%d\n",p.next);
	}
	return 0;
}
