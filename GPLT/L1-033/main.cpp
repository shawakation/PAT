#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;
int butong(string a)
{
	set<char> my;
	for (int i=0;i<4;i++) my.insert(a[i]);
	return my.size();
}
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	string s=ss.str();
	while (s.length()<4) s.insert(0,"0");
	return s;
}
int main()
{
	int date,x,countt=0;
	scanf("%d %d",&date,&x);
	while (butong(inttostr(date))!=x) countt++,date++;
	printf("%d %04d\n",countt,date);
	return 0;
}
