#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
int strtoint(string a)
{
	stringstream ss(a);
	int num;
	ss>>num;
	return num;
}
int main()
{
	int n;
	string basic[]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
	string jin[]={"tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		string s;
		getline(cin,s,'\n');
		if (isdigit(s[0])) {
			int aa=strtoint(s);
			int zheng=aa/13;
			int yu=aa-zheng*13;
			if (zheng==0) cout<<basic[yu]<<endl;
			else cout<<jin[zheng-1]<<' '<<basic[yu]<<endl;
		}
		else {
			bool flag=false;
			for (int j=0;j<s.length();j++) {
				if (isblank(s[j])) {
					flag=true;
					int zheng,yu;
					string temp=s.substr(0,j);
					for (int k=0;k<12;k++)
						if (temp==jin[k]) {
							zheng=k+1;
							break;
						}
					string temp2=s.substr(j+1,s.length()-j-1);
					for (int k=0;k<13;k++)
						if (temp2==basic[k]) {
							yu=k;
							break;
						}
					cout<<zheng*13+yu<<endl;
					break;
				}
			}
			if (!flag) {
				int yu;
				bool flag=false;
				for (int k=0;k<13;k++)
					if (s==basic[k]) {
						flag=true;
						yu=k;
						break;
					}
				if (!flag)
					for (int k=0;k<12;k++)
						if (s==jin[k]) {
							yu=13*(k+1);
							break;
						}
				cout<<yu<<endl;
			}
		}
	}
	return 0;
}
