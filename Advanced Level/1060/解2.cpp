/*
1.难题，题意读明白
2.逻辑！！！！好难啊。。。。。。
3.注意是 0 的情况 要输出 0*10^0
    类似有 0.232*10^0
*/
#include <iostream>
#include <string>
using namespace std;
int k=0;
string convert(string s,int &e)
{
	e=0;
	int m=0,num=0;
	string res;
	while (s[0]=='0'&&s.length()>0) s.erase(0,1);
	if (s[0]=='.') {
		s.erase(0,1);
		while (s[0]=='0'&&s.length()>0) {
			s.erase(0,1);
			e--;
		}
	} else {
		while (s[m]!='.'&&m<s.length()) {
			m++;e++;
		}
		if (m<s.length()) s.erase(m,1);
	}
	if (s.length()==0) e=0;
	m=0;
	while (num<k) {
		if (m<s.length()) res+=s[m++];
		else res+="0";
		num++;
	}
	return res;
}
int main()
{
	string a,b,a1,b1;
	int a2,b2;
	cin>>k>>a>>b;
	a1=convert(a,a2);
	b1=convert(b,b2);
	if (a1==b1&&a2==b2) cout<<"YES 0."<<a1<<"*10^"<<a2<<endl;
	else cout<<"NO 0."<<a1<<"*10^"<<a2<<" 0."<<b1<<"*10^"<<b2<<endl;
	return 0;
}
