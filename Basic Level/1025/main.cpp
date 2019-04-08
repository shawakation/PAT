#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node
{
	int address;
	int data;
	int nextadd;
};
int main()
{
	int start,n,m;
	vector<node> nodes;
	cin>>start>>n>>m;
	for (int i=0;i<n;i++) {
		node temp;
		cin>>temp.address>>temp.data>>temp.nextadd;
		nodes.push_back(temp);
	}
	int i=0,addr=start;
	while (addr!=-1) {
		for (int k=i;k<nodes.size();k++) {
			if (nodes[k].address==addr) {
				addr=nodes[k].nextadd;
				node tt=nodes[k];
				nodes[k]=nodes[i];
				nodes[i]=tt;
				i++;
				break;
			}
		}
	}
	reverse(nodes.begin(),nodes.begin()+m);
	nodes[m-1].nextadd=nodes[0].nextadd;
	for (i=0;i<m-1;i++) {
		nodes[i].nextadd=nodes[i+1].address;
	}
	for (i=0;i<nodes.size();i++) {
		if (nodes[i].nextadd!=-1)
			printf("%05d %d %05d\n",nodes[i].address,nodes[i].data,nodes[i].nextadd);
  		else
			printf("%05d %d %d\n",nodes[i].address,nodes[i].data,nodes[i].nextadd);
	}
	return 0;
}
