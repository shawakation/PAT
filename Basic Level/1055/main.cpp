#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct node
{
	int height;
	string name;
};
bool cmp(struct node a,struct node b)
{
	return a.height!=b.height?a.height>b.height:a.name<b.name;
}
int main()
{
	int n,k;
	cin>>n>>k;
	vector<node> que(n);
	for (int i=0;i<n;i++) {
		cin>>que[i].name>>que[i].height;
	}
	sort(que.begin(),que.end(),cmp);
	int aa=0;
	for (int i=k;i>=1;i--) {
		int m;
		if (i==k) m=n-(k-1)*(n/k);
		else m=n/k;
		vector<string> stu(m);
		stu[m/2]=que[aa++].name;
		int bb=1,cc=1;
		while (m/2+bb<m||m/2-cc>=0) {
			if (m/2-cc>=0) {
				stu[m/2-cc]=que[aa++].name;
				cc++;
			}
			if (m/2+bb<m) {
				stu[m/2+bb]=que[aa++].name;
				bb++;
			}
		}
		for (int g=0;g<stu.size();g++) {
			cout<<stu[g];
			if (g!=stu.size()-1) cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
