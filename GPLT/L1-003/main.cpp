#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	string num;
	map<char,int> my;
	cin>>num;
	for (auto &p:num) my[p]++;
	for (auto &p:my) cout<<p.first<<':'<<p.second<<endl;
	return 0;
}
