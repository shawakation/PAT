#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
	string buy,need;
	unordered_map<char,int> my;
	int que=0;
	getline(cin,buy,'\n');
	getline(cin,need,'\n');
	for (int i=0;i<buy.length();i++) my[buy[i]]++;
	for (int i=0;i<need.length();i++) {
		if (my.find(need[i])!=my.end()) {
			if (my[need[i]]<=0) que++;
			else my[need[i]]--;
		}
		else que++;
	}
	if (que>0) cout<<"No "<<que;
	else cout<<"Yes "<<buy.length()-need.length();
	return 0;
}
