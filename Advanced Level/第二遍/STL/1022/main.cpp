#include <bits/stdc++.h>
using namespace std;
struct book
{
	string info[6];
	book() {
		for (int i=0;i<6;i++) info[i]="";
	}
	friend bool operator < (const book &a,const book &b) {
		return a.info[0]<b.info[0];
	}
};
vector<book> arr;
int main()
{
	int n,m;
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		book tt;
		for (int j=0;j<6;j++) getline(cin,tt.info[j],'\n');
		arr.push_back(tt);
	}
	sort(arr.begin(),arr.end());
	cin>>m;
	cin.ignore();
	for (int i=0;i<m;i++) {
		string query;
		getline(cin,query,'\n');
		printf("%s\n",query.c_str());
		int p=query[0]-'0';
		query.erase(0,3);
		if (p!=3) {
			bool flag=1;
			for (book &w:arr) if (w.info[p]==query) {
				printf("%s\n",w.info[0].c_str());
				flag=0;
			}
			if (flag) printf("Not Found\n");
		}
		else {
			bool flag=1;
			for (book &w:arr) if (w.info[p].find(query)!=string::npos) {
				printf("%s\n",w.info[0].c_str());
				flag=0;
			}
			if (flag) printf("Not Found\n");
		}
	}
	return 0;
}
