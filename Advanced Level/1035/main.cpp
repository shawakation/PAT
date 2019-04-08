#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	vector<string> name1;
	vector<string> psw1;
	cin>>n;
	for (int i=0;i<n;i++) {
		string name,psw;
		bool flag=0;
		cin>>name>>psw;
		for (int k=0;k<psw.length();k++) {
			if (psw[k]=='1') {
				psw[k]='@';
				flag=1;
			}
			else if (psw[k]=='0') {
				psw[k]='%';
				flag=1;
			}
			else if (psw[k]=='l') {
				psw[k]='L';
				flag=1;
			}
			else if (psw[k]=='O') {
				psw[k]='o';
				flag=1;
			}
		}
		if (flag) {
			name1.push_back(name);
			psw1.push_back(psw);
		}
	}
	int countt=name1.size();
	if (countt) {
		cout<<countt<<endl;
		for (int i=0;i<countt;i++) {
			cout<<name1[i]<<' '<<psw1[i]<<endl;
		}
	}
	else {
		if (n==1) cout<<"There is 1 account and no account is modified\n";
		else cout<<"There are "<<n<<" accounts and no account is modified\n";
	}
	return 0;
}
