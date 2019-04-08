#include <cstdio>
#include <cmath>
#include <string.h>
#include <memory.h>
using namespace std;
int main()
{
	char sale[1001],buy[1001];
	short countt[255];
	memset(sale,'\0',sizeof(sale));
	memset(buy,'\0',sizeof(buy));
	memset(countt,0,sizeof(countt));
	scanf("%s",sale);
	scanf("%s",buy);
	for (unsigned short i=0;sale[i]!='\0';i++)
		countt[sale[i]]++;
	unsigned short more=abs(strlen(sale)-strlen(buy));
	unsigned short less=0;
	for (unsigned short i=0;buy[i]!='\0';i++) {
		countt[buy[i]]--;
		if (countt[buy[i]]<0) less++;
	}
	if (less==0) printf("Yes %d",more);
	else printf("No %d",less);
	return 0;
}
