/*
1.注意当分数部分小数点后的位数等于指数时不要往最后加上 '.'
*/
#include <bits/stdc++.h>
using namespace std;
int strtoint(string a)
{
	stringstream s(a);
	int b;
	s>>b;
	return b;
}
int main()
{
	string s,ans;
	getline(cin,s,'\n');
	if (s[0]=='-') ans+="-";
	s.erase(0,1);
	int dot=0,exp=0;
	while (s[exp]!='E') exp++;
	string Ex=s.substr(exp+1,s.length()-exp-1);
	string frac=s.substr(0,exp);
	while (frac[dot]!='.') dot++;
	if (Ex[0]=='-') {
		Ex.erase(0,1);
		int expon=strtoint(Ex);
		frac.erase(dot,1);
		while (expon>1) {
			frac.insert(0,"0");
			expon--;
		}
		frac.insert(0,"0.");
	}
	else {
		Ex.erase(0,1);
		int tt=frac.length()-dot-1,expon=strtoint(Ex);
		frac.erase(dot,1);
		if (tt<expon) frac.append(expon-tt,'0');
		else if (tt>expon) frac.insert(dot+expon,".");
	}
	ans+=frac;
	printf("%s\n",ans.c_str());
	return 0;
}
