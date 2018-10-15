#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int n;
	cin>>n;
	cin.ignore();		//getline前加ignore 
	for (int i=0;i<n;i++) {
		string passwd;
		bool isNum=false;
		bool isAlpha=false;
		getline(cin,passwd,'\n');
		if (passwd.length()<6) {
			cout<<"Your password is tai duan le.\n";
			goto overr;
		}
		for (int j=0;j<passwd.length();j++) {
			if (passwd[j]!='.'&&(!isalnum(passwd[j])))		//注意这里 
			{
				cout<<"Your password is tai luan le.\n";
				goto overr;
			}
			if (isdigit(passwd[j])) isNum=true;
			if (isalpha(passwd[j])) isAlpha=true;
		}
		if (!isNum) {
			cout<<"Your password needs shu zi.\n";
			goto overr;
		}
		if (!isAlpha) {
			cout<<"Your password needs zi mu.\n";
			goto overr;
		}
		cout<<"Your password is wan mei.\n";
		overr:;
	}
	return 0;
}
