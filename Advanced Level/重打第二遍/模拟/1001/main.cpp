#include <bits/stdc++.h>
using namespace std;
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c=a+b;
	string s=inttostr(c);
	for (int i=s.length()-1;i>=0;i-=3) if (i<s.length()-1&&s[i]!='-') s.insert(i+1,",");
	cout<<s;
	return 0;
}
