#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int strtoint(string s) {
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
int main()
{
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	cout<<strtoint(s)<<endl;
	return 0;
}
