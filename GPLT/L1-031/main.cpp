#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int h,w;
		scanf("%d%d",&h,&w);
		float biaozhunw=(h-100)*0.9,shijiw=w/2.0f;
		if (abs(shijiw-biaozhunw)<biaozhunw*0.1) printf("You are wan mei!\n");
		else if (shijiw>biaozhunw) printf("You are tai pang le!\n");
		else if (shijiw<biaozhunw) printf("You are tai shou le!\n");
	}
	return 0;
}
