#include <bits/stdc++.h>
using namespace std;
string low[]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[]={"","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
string numtomar(int n)
{
	int lownum=n%13;
	n/=13;
	int highnum=n%13;
	string ans;
	if (highnum>0) ans+=high[highnum];
	if (highnum>0&&lownum>0) ans+=" "+low[lownum];
	else if (highnum==0) ans+=low[lownum];
	return ans;
}
int martonum(string s)
{
	if (s.length()>4) {
		int h=0;
		while (s[h]!=' ') h++;
		string s1=s.substr(0,h),s2=s.substr(h+1,s.length()-h-1);
		int lownum=1,highnum=1;
		for (;lownum<13;lownum++) if (low[lownum]==s2) break;
		for (;highnum<13;highnum++) if (high[highnum]==s1) break;
		return highnum*13+lownum;
	}
	else {
		for (int h=0;h<13;h++) if (low[h]==s) return h;
		for (int h=1;h<13;h++) if (high[h]==s) return h*13;
	}
}
int main()
{
	int n;
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		string s;
		getline(cin,s,'\n');
		if (isdigit(s[0])) cout<<numtomar(strtoint(s))<<endl;
		else cout<<martonum(s)<<endl;
	}
	return 0;
}
