/*
»ù±¾Ì×Â·¡£¡£¡£
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;
struct node {
	int addr,data,next;
};
int main()
{
	int startaddr,n;
	scanf("%d %d",&startaddr,&n);
	unordered_map<int,node> my;
	unordered_map<int,int> countt;
	for (int i=0; i<n; i++) {
		node tt;
		scanf("%d %d %d",&tt.addr,&tt.data,&tt.next);
		my[tt.addr]=tt;
	}
	vector<node> arr,removed;
	for (int p=startaddr; p!=-1; p=my[p].next) {
		countt[abs(my[p].data)]++;
		if (countt[abs(my[p].data)]>1) removed.push_back(my[p]);
		else arr.push_back(my[p]);
	}
	for (int i=0; i<arr.size(); i++) {
		if (i<arr.size()-1) arr[i].next=arr[i+1].addr;
		else arr[i].next=-1;
	}
	for (int i=0; i<removed.size(); i++) {
		if (i<removed.size()-1) removed[i].next=removed[i+1].addr;
		else removed[i].next=-1;
	}
	for (auto &p:arr) {
		if (p.next!=-1) printf("%05d %d %05d\n",p.addr,p.data,p.next);
		else printf("%05d %d %d\n",p.addr,p.data,p.next);
	}
	for (auto &p:removed) {
		if (p.next!=-1) printf("%05d %d %05d\n",p.addr,p.data,p.next);
		else printf("%05d %d %d\n",p.addr,p.data,p.next);
	}
	return 0;
}
