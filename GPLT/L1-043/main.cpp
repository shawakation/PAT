#include <bits/stdc++.h>
using namespace std;
struct abook
{
	public:
		bool isBorrow;
		int starthour,startminute;
	public:
		abook()
		{
			isBorrow=false;
			starthour=0;
			startminute=0;
		}
};
int main()
{
	int n,countt=0,borrow=0,sumtime=0;
	cin>>n;
	vector<abook> boook(1001);
	while (1) {
		int book,hour,minute;
		char c;
		scanf("%d %c %d:%d",&book,&c,&hour,&minute);
		if (book==0) {
			int aa;
			if (borrow==0) aa=0;
			else aa=round((float)sumtime/(float)borrow);
			printf("%d %d\n",borrow,aa);
			countt++;
			borrow=sumtime=0;
			if (countt==n) return 0;
		}
		else if (c=='S') {
			boook[book].isBorrow=true;
			boook[book].starthour=hour;
			boook[book].startminute=minute;
		}
		else if (c=='E') {
			if (boook[book].isBorrow==true) {
				borrow++;
				if (boook[book].startminute<=minute) {
					sumtime+=(hour-boook[book].starthour)*60+(minute-boook[book].startminute);
				}
				else if (boook[book].startminute>minute) {
					sumtime+=(hour-boook[book].starthour-1)*60+(minute+60-boook[book].startminute);
				}
				boook[book].isBorrow=false;
			}
		}
	}
	return 0;
}
