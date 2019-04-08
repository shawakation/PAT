/*
1.注意题目中的范围，并没有说只是四位整数
*/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
int main()
{
	string s;
	cin>>s;
	while (s.length()<4) s.insert(0,"0");
	do {
		sort(s.begin(),s.end());
		int a=strtoint(s);
		reverse(s.begin(),s.end());
		int b=strtoint(s);
		int c=b-a;
		printf("%04d - %04d = %04d\n",b,a,c);
		s=inttostr(c);
		while (s.length()<4) s.insert(0,"0");
	} while (s!="6174"&&s!="0000");
	return 0;
}
