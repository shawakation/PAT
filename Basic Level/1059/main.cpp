/*
1.algorithm中要掌握的4个函数及其功能：
	find  sort   reverse   for_each
	注意 string.find 与 map.find string 与 map 自带
2.iterator指针转化为下标的方法：
(1)(int)(it-a.begin())
(2) iterator头文件中的distance  advance函数
*/
#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
bool isprime(int n)
{
	for (int j=2;j<=(int)sqrt(n);j++) {
		if (n%j==0) return false;
	}
	return true;
}
int main()
{
	int n,k,ischeck[10000];
	memset(ischeck,0,sizeof(ischeck));
	cin>>n;
	deque<int> ids;
	for (int i=0;i<n;i++) {
		int stuid;
		cin>>stuid;
		ids.push_back(stuid);
	}
	cin>>k;
	for (int i=0;i<k;i++) {
		int checknum;
		cin>>checknum;
		deque<int>::iterator it=find(ids.begin(),ids.end(),checknum);
		if (it==ids.end()) {
			printf("%04d: Are you kidding?\n",checknum);
			continue;
		}
		if (ischeck[*it]==1) {
			printf("%04d: Checked\n",checknum);
			continue;
		}
		if (it==ids.begin()) {
			printf("%04d: Mystery Award\n",checknum);
			ischeck[*it]=1;
		}
		else if (isprime((int)(it-ids.begin())+1)) {
			printf("%04d: Minion\n",checknum);
			ischeck[*it]=1;
		}
		else {
			printf("%04d: Chocolate\n",checknum);
			ischeck[*it]=1;
		}
	}
	return 0;
}
