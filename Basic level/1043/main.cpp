/*
题目要点：用数组来统计元素个数
*/
#include <iostream>
#include <string>
#include <memory.h>
using namespace std;
int main()
{
	string ss;
	unsigned short num[6];
	memset(num,0,sizeof(num));
	cin>>ss;
	for (unsigned short i=0;i<ss.size();i++)
		switch (ss[i]) {
			case 'P':{
				num[0]++;
				break;
			}
			case 'A':{
				num[1]++;
				break;
			}
			case 'T':{
				num[2]++;
				break;
			}
			case 'e':{
				num[3]++;
				break;
			}
			case 's':{
				num[4]++;
				break;
			}
			case 't':{
				num[5]++;
				break;
			}
		}
	while (1) {
		if (num[0]!=0) {
			cout<<'P';
			num[0]--;
		}
		if (num[1]!=0) {
			cout<<'A';
			num[1]--;
		}
		if (num[2]!=0) {
			cout<<'T';
			num[2]--;
		}
		if (num[3]!=0) {
			cout<<'e';
			num[3]--;
		}
		if (num[4]!=0) {
			cout<<'s';
			num[4]--;
		}
		if (num[5]!=0) {
			cout<<'t';
			num[5]--;
		}
		if (num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0&&num[5]==0) break;
	}
	return 0;
}
