#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	map<int,int> my;
	cin>>n;
	for (int i=1;i<=n;i++) {
		int num;
		cin>>num;
		int aa=abs(i-num);
		my[aa]++;
	}
	for (map<int,int>::iterator p=(--my.end());p!=my.begin();p--) {
		if (p->second>1) cout<<p->first<<' '<<p->second<<endl;
	}
	map<int,int>::iterator it=my.begin();
	if (it->second>1) cout<<it->first<<' '<<it->second<<endl;
	return 0;
}
