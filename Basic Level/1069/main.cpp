#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
int main()
{
	int m,n,s;
	bool flag=true;
	deque<string> zhuanfa;
	deque<string> yizhuanfa;
	cin>>m>>n>>s;
	cin.ignore();
	for (int i=0;i<m;i++) {
		string per;
		getline(cin,per,'\n');
		zhuanfa.push_back(per);
	}
	while (s<=m) {
		deque<string>::iterator it=find(yizhuanfa.begin(),yizhuanfa.end(),zhuanfa[s-1]);
		if (it==yizhuanfa.end()) {
			cout<<zhuanfa[s-1]<<endl;
			yizhuanfa.push_back(zhuanfa[s-1]);
			flag=false;
			s+=n;
		}
		else {
			s++;
		}
	}
	if (flag) cout<<"Keep going...\n";
	return 0;
}
