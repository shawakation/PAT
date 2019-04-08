/*
1.scanf中格式字符%s专门用来输入char数组型字符串
2.printf中%04d格式控制字符，不够4个在前面补0
*/
#include <iostream>
#include <memory.h>
using namespace std;
int main()
{
	int n,m,wentistu=0,wupinzong=0;
	cin>>n>>m;
	int *wupin=new int[m];
	for (int i=0;i<m;i++) cin>>wupin[i];
	for (int i=0;i<n;i++) {
		char stuname[5];
		int k;
		scanf("%s",stuname);
		cin>>k;
		bool flag=true;
		for (int j=0;j<k;j++) {
			int stuwupin;
			cin>>stuwupin;
			for (int aa=0;aa<m;aa++)
				if (wupin[aa]==stuwupin) {
					if (flag) {
						cout<<stuname<<":";
						wentistu++;
					}
					flag=false;
					wupinzong++;
					printf(" %04d",wupin[aa]);
				}
		}
		if (!flag) cout<<endl;
	}
	cout<<wentistu<<' '<<wupinzong;
	return 0;
}
