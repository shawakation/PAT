#include <iostream>
using namespace std;
int main()
{
	int hour,minute;
	scanf("%d:%d",&hour,&minute);
	if (hour>=0&&hour<=11||hour==12&&minute==0)
		printf("Only %02d:%02d.  Too early to Dang.\n",hour,minute);
	else {
		if (minute>0) hour++;
		for (int i=0;i<hour-12;i++) printf("Dang");
		printf("\n");
	}
	return 0;
}
