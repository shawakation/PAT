#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct problem
{
	int mark;
	int options;
	vector<char> right;
};
int main()
{
	int n,m;
	map<string,int> error;
	multimap<int,string> error2;
	cin>>n>>m;
	vector<problem> arr;
	for (int i=0;i<m;i++) {
		int fullmark,options,rights;
		problem temp;
		cin>>fullmark>>options>>rights;
		temp.mark=fullmark;
		temp.options=options;
		for (int k=0;k<rights;k++) {
			char opt;
			cin>>opt;
			temp.right.push_back(opt);
		}
		arr.push_back(temp);
	}
	for (int i=0;i<n;i++) {
		float score=0;
		for (int yy=0;yy<m;yy++) {
			int a,countt=0,flag=0;
			vector<char> choose;
			cin.get();
			cin.get();
			cin>>a;
			for (int h=0;h<a;h++) {
				char opt;
				cin>>opt;
				choose.push_back(opt);
				vector<char>::iterator it=find(arr[m].right.begin(),arr[m].right.end(),opt);
				if (it!=arr[m].right.end()) {
					countt++;
				}
				else {
					flag=1;
					string ss="";
					ss.insert(ss.length()-1,to_string(m+1));
					ss.insert(ss.length()-1,"-");
					ss.insert(ss.end(),opt);
					error[ss]++;
				}
			}
			cin.get();
			if (flag==0) {
				if (choose.size()<arr[m].right.size()) {
					score+=arr[m].mark*0.5f;
				}
				else if (choose.size()==arr[m].right.size()) {
					score+=arr[m].mark;
				}
			}
		}
		printf("%.1f\n",score);
	}
	for (map<string,int>::iterator p=error.begin();p!=error.end();p++) {
		string s1=p->first;
		int s2=p->second;
		error2.insert(pair<int,string>(s2,s1));
	}
	map<int,string>::iterator ir=--error2.end();
	int max=ir->first;
	for (;ir->first==max;ir--) {
		cout<<ir->first<<' '<<ir->second<<endl;
	}
	return 0;
}
