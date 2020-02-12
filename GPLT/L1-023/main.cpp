#include <string>
#include <iostream>
#include <map>
#include <cctype>
using namespace std;
int main() {
	map<int,char> my;
	my.insert(make_pair(0,'G'));
	my.insert(make_pair(1,'P'));
	my.insert(make_pair(2,'L'));
	my.insert(make_pair(3,'T'));
	int countt[4]={0};
	string s;
	cin>>s;
	for (char &p:s) {
		switch (toupper(p)) {
			case 'G':
				countt[0]++;
				break;
			case 'P':
				countt[1]++;
				break;
			case 'L':
				countt[2]++;
				break;
			case 'T':
				countt[3]++;
				break;
		}
	}
	while (!(countt[0]==0&&countt[1]==0&&countt[2]==0&&countt[3]==0)) {
		for (int i=0;i<4;i++) {
			if (countt[i]>0) {
				printf("%c",my[i]);
				countt[i]--;
			}
		}
	}
	printf("\n");
	return 0;
}
