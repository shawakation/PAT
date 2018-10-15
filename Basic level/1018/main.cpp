#include <iostream>
#include <queue>
using namespace std;
unsigned short jiasheng=0,jiafu=0,yisheng=0,yifu=0,pingju=0;
queue<char> jia1sheng,yi1sheng;
void judge(char jia,char yi)
{
	if (jia=='C') {
		if (yi=='J') {
			jiasheng++;
			yifu++;
			jia1sheng.push('C');
			return;
		}
		if (yi=='B') {
			yisheng++;
			jiafu++;
			yi1sheng.push('B');
			return;
		}
		if (yi=='C') {
			pingju++;
			return;
		}
	}
	if (jia=='J') {
		if (yi=='C') {
			yisheng++;
			jiafu++;
			yi1sheng.push('C');
			return;
		}
		if (yi=='B') {
			jiasheng++;
			yifu++;
			jia1sheng.push('J');
			return;
		}
		if (yi=='J') {
			pingju++;
			return;
		}
	}
	if (jia=='B') {
		if (yi=='B') {
			pingju++;
			return;
		}
		if (yi=='C') {
			jiasheng++;
			yifu++;
			jia1sheng.push('B');
			return;
		}
		if (yi=='J') {
			yisheng++;
			jiafu++;
			yi1sheng.push('J');
			return;
		}
	}
}
int main()
{
	unsigned int N;
	unsigned short jiaJ=0,jiaB=0,jiaC=0;
	unsigned short yiJ=0,yiB=0,yiC=0;
	cin>>N;
	for (unsigned int i=0;i<N;i++) {
		char jia,yi;
		cin>>jia>>yi;
		judge(jia,yi);
	}
	while (!jia1sheng.empty()) {
		switch (jia1sheng.front()) {
			case 'J':{
				jiaJ++;
				break;
			}
			case 'B':{
				jiaB++;
				break;
			}
			case 'C':{
				jiaC++;
				break;
			}
		}
		jia1sheng.pop();
	}
	while (!yi1sheng.empty()) {
		switch (yi1sheng.front()) {
			case 'J':{
				yiJ++;
				break;
			}
			case 'B':{
				yiB++;
				break;
			}
			case 'C':{
				yiC++;
				break;
			}
		}
		yi1sheng.pop();
	}
	cout<<jiasheng<<' '<<pingju<<' '<<jiafu<<'\n';
	cout<<yisheng<<' '<<pingju<<' '<<yifu<<'\n';
	if (jiaB>=jiaC&&jiaB>=jiaJ) cout<<'B';
	else if (jiaC>=jiaB&&jiaC>=jiaJ) cout<<'C';
	else if (jiaJ>=jiaB&&jiaJ>=jiaC) cout<<'J';
	cout<<' ';
	if (yiB>=yiC&&yiB>=yiJ) cout<<'B';
	else if (yiC>=yiB&&yiC>=yiJ) cout<<'C';
	else if (yiJ>=yiB&&yiJ>=yiC) cout<<'J';
	return 0;
}
