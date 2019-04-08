#include <iostream>
#include <sstream>
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
	cin>>a>>b;
	int c=a+b;
	string s=inttostr(c);
	for (int i=1,k=s.length()-1;k>=0;k--,i++) {
		if (i%3==0&&k&&s[k-1]!='-') s.insert(k,",");
	}
	cout<<s;
	return 0;
}
