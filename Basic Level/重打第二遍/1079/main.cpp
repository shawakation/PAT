#include <bits/stdc++.h>
using namespace std;
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
struct problem
{
	public:
	int fullmark;
	int optnum;
	int rightoptnum;
	int opt[5];
	public:
	problem()
	{
		fullmark=optnum=rightoptnum=0;
		for (short i=0;i<5;i++) opt[i]=0;
	}
};
int main()
{
	int n,m;
	cin>>n>>m;
	vector<problem> arr(m);
	map<string,int> error;
	for (int i=0;i<m;i++) {
		cin>>arr[i].fullmark>>arr[i].optnum>>arr[i].rightoptnum;
		for (int j=0;j<arr[i].rightoptnum;j++) {
			char opts;
			cin>>opts;
			arr[i].opt[opts-'a']=1;
		}
	}
	cin.clear();
	cin.sync();
	for (int i=0;i<n;i++) {
		float grade=0.0f;
		for (int j=0;j<m;j++) {
			int num,choice[5]={0};
			bool meiquan=false,cuowu=false;
			cin.get();
			cin>>num;
			for (int k=0;k<num;k++) {
				char choic;
				cin>>choic;
				choice[choic-'a']=1;
			}
			cin.get();
			cin.get();
			for (int aa=0;aa<arr[j].optnum;aa++) {
				if (choice[aa]>arr[j].opt[aa]) {
					cuowu=true;
					char qq='1'+j,ww='a'+aa;
					string err="";
					err+=qq;
					err+='-';
					err+=ww;
					error[err]++;
				}
				if (choice[aa]<arr[j].opt[aa]) {
					meiquan=true;
					char qq='1'+j,ww='a'+aa;
					string err="";
					err+=qq;
					err+='-';
					err+=ww;
					error[err]++;
				}
			}
			if (!cuowu&&!meiquan) grade+=(float)arr[j].fullmark;
			else if (!cuowu&&meiquan) grade+=(float)arr[j].fullmark*0.5f;
		}
		printf("%.1f\n",grade);
	}
	if (error.empty()) {
		cout<<"Too simple\n";
		return 0;
	}
	int maxerr=0;
	for (map<string,int>::iterator p=error.begin();p!=error.end();p++) {
		if (p->second>maxerr) maxerr=p->second;
	}
	for (map<string,int>::iterator p=error.begin();p!=error.end();p++) {
		if (p->second==maxerr) cout<<maxerr<<' '<<p->first<<endl;
	}
	return 0;
}
