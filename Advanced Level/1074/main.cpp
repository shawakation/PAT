/*
1.基本套路：遍历之后再进行其他操作
            用 unordered_map 先存无序的，然后用遍历的方式把节点存入 vector
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
	int addr,data,next;
	node() {
		addr=data=next=0;
	}
};
int main()
{
	int startaddr,n,k;
	scanf("%d %d %d",&startaddr,&n,&k);
	unordered_map<int,node> my;
	vector<node> arr;
	for (int i=0; i<n; i++) {
		node tt;
		scanf("%d %d %d",&tt.addr,&tt.data,&tt.next);
		my[tt.addr]=tt;
	}
	for (int p=startaddr; p!=-1; p=my[p].next) arr.push_back(my[p]);
	for (int i=0; i<arr.size(); i+=k)
		if (i+k<=arr.size()) reverse(arr.begin()+i,arr.begin()+i+k);
	for (int i=0; i<arr.size(); i++) {
		if (i<arr.size()-1) arr[i].next=arr[i+1].addr;
		else arr[i].next=-1;
	}
	for (auto &p:arr) {
		printf("%05d %d ",p.addr,p.data);
		if (p.next!=-1) printf("%05d\n",p.next);
		else printf("%d\n",p.next);
	}
	return 0;
}
