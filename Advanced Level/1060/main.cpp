/*
1.不是最优解，写的太繁琐了
*/
#include <iostream>
#include <string>
using namespace std;
int k=0;
bool comp(string a,string b)
{
	if (a=="0"&&b=="0") return 1;
	else if (a=="0"&&b!="0") return 0;
	else if (a!="0"&&b=="0") return 0;
	else for (int i=2; i<2+k; i++) if (a[i]!=b[i]) return 0;
	return 1;
}
string convert(string s)
{
	if (s=="0") return s;
	int dot=0,nozero=0,len=s.length();
	while (dot<len&&s[dot]!='.') dot++;
	while (nozero<len&&(s[nozero]=='0'||s[nozero]=='.')) nozero++;
	if (dot<nozero) {
		int exp=nozero-dot-1;
		s.erase(dot+1,nozero-dot-1);
		if (exp) {
			s+="*10^-";
			s+=char(exp+'0');
		}
	} else {
		if (dot<len) s.erase(dot,1);
		s.insert(0,"0.");
		s+="*10^";
		s+=char(dot-nozero+'0');
	}
	return s;
}
int main()
{
	string a,b;
	cin>>k>>a>>b;
	while (a[0]=='0'&&a[1]!='.'&&a.length()>1) a.erase(0,1);
	while (b[0]=='0'&&b[1]!='.'&&b.length()>1) b.erase(0,1);
	a=convert(a);
	b=convert(b);
	if (comp(a,b)) {
		cout<<"YES ";
		if (a=="0") cout<<"0";
		else {
			int i=0;
			while (a[i]!='*') i++;
			if (k+2<i) a.erase(k+2,i-k-2);
			cout<<a;
		}
	} else {
		cout<<"NO ";
		if (a=="0") cout<<"0 ";
		else {
			int i=0;
			while (a[i]!='*') i++;
			if (k+2<i) a.erase(k+2,i-k-2);
			cout<<a<<' ';
		}
		if (b=="0") cout<<"0";
		else {
			int j=0;
			while (b[j]!='*') j++;
			if (k+2<j) b.erase(k+2,j-k-2);
			cout<<b;
		}
	}
	return 0;
}
