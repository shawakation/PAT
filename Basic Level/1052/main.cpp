/*
1.vector二维数组的应用
2.string substr函数
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	vector<vector<string>> strs;
	for (int i=0;i<3;i++) {
		string ss;
		vector<string> temp;
		getline(cin,ss,'\n');
		for (unsigned int j=0;j<ss.length();j++) {
			unsigned int k;
			if (ss[j]=='[') {
				k=j+1;
				while (ss[k]!=']') k++;
				string sstr=ss.substr(j+1,k-j-1);
				temp.push_back(sstr);
			}
		}
		strs.push_back(temp);
	}
	int n;
	cin>>n;
	for (int i=0;i<n;i++) {
		unsigned int a,b,c,d,e;
		cin>>a>>b>>c>>d>>e;
		if (a<=strs[0].size()&&b<=strs[1].size()&&c<=strs[2].size()&&d<=strs[1].size()&&e<=strs[0].size())
		{
			cout<<strs[0][a-1]<<'('<<strs[1][b-1]<<strs[2][c-1]<<strs[1][d-1]<<')'<<strs[0][e-1];
			cout<<'\n';
		}
		else {
			cout<<"Are you kidding me? @\\/@\n";
		}
	}
	return 0;
}
