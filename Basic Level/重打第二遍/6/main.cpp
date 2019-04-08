#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		string ss;
		bool hasAlpha=false,hasNum=false,flag=true;
		getline(cin,ss,'\n');
		if (ss.length()<6) cout<<"Your password is tai duan le.\n";
		else {
			for (int k=0;k<ss.length();k++) {
				if (!(isalnum(ss[k])||ss[k]=='.')) {
					cout<<"Your password is tai luan le.\n";
					flag=false;
					break;
				}
				if (isdigit(ss[k])) hasNum=true;
				if (isalpha(ss[k])) hasAlpha=true;
			}
			if (flag) {
				if ((!hasNum)&&hasAlpha) cout<<"Your password needs shu zi.\n";
				else if ((!hasAlpha)&&hasNum) cout<<"Your password needs zi mu.\n";
				else cout<<"Your password is wan mei.\n";
			}
		}
	}
	return 0;
}
