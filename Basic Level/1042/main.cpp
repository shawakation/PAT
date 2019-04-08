#include <iostream>
#include <cctype>
#include <string>
#include <memory.h>
using namespace std;
int main()
{
	string ss;
	char maxchar;
	unsigned short max=0;
	unsigned short countt[26];
	memset(countt,0,sizeof(countt));
	getline(cin,ss,'\n');
	for (short i=0;i<ss.length();i++) {
		if (isalpha(ss[i])) {
			ss[i]=tolower(ss[i]);
			countt[ss[i]-'a']++;
		}
	}
	for (short i=0;i<26;i++) {
		if (countt[i]>max) {
			max=countt[i];
			maxchar=i+'a';
		}
	}
	printf("%c %d",maxchar,max);
	return 0;
}
