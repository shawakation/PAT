/*
注意使用哈希表 unordered_set 减少开销
*/
#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;
int main()
{
	string s1,s2;
	unordered_set<char> broke;
	getline(cin,s1,'\n');
	getline(cin,s2,'\n');
	s2.append('!',s1.length()-s2.length());
	int m=0,n=0;
	while (m<s1.length()&&n<s2.length()) {
		if (tolower(s1[m])==tolower(s2[n])) {
			m++;
			n++;
		}
		else {
			if (broke.find(toupper(s1[m]))==broke.end()) {
				printf("%c",toupper(s1[m]));
				broke.insert(toupper(s1[m]));
			}
			m++;
		}
	}
	return 0;
}
