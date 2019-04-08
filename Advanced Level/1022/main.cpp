#include <iostream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;
struct book {
	string info[5];
};
int main()
{
	int n,m;
	map<string,book> my;
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		string id;
		book newbook;
		cin>>id;
		getchar();
		for (int l=0; l<5; l++) getline(cin,newbook.info[l],'\n');
		my[id]=newbook;
	}
	scanf("%d",&m);
	for (int i=0; i<m; i++) {
		string query;
		int num;
		scanf("%d: ",&num);
		getline(cin,query,'\n');
		cout<<num<<": "<<query<<endl;
		if (num==3) {
			bool flag=1;
			for (auto p=my.begin(); p!=my.end(); p++) {
				if ((p->second).info[2].find(query)!=string::npos) {
					flag=0;
					cout<<p->first<<endl;
				}
			}
			if (flag) printf("Not Found\n");
		} else {
			bool flag=1;
			for (auto p=my.begin(); p!=my.end(); p++) {
				if ((p->second).info[num-1]==query) {
					cout<<p->first<<endl;
					flag=0;
				}
			}
			if (flag) printf("Not Found\n");
		}
	}
	return 0;
}
