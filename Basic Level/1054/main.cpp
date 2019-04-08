/*
1.sscanf sprintf的用法和意义
2.string.h(cstring)中的三个函数：strlen strcpy strcmp
3.scanf %s 输入char数组型字符串
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <memory.h>
using namespace std;
int main()
{
	int n,countt=0;
	double sum=0;
	cin>>n;
	for (int i=0;i<n;i++) {
		char ss[100],convertss[100];
		bool flag=true;
		double temp;
		scanf("%s",ss);
		sscanf(ss,"%lf",&temp);
		sprintf(convertss,"%.2lf",temp);
		for (int k=0;k<strlen(ss);k++) {
			if (ss[k]!=convertss[k]) {
				printf("ERROR: %s is not a legal number\n",ss);
				flag=false;
				break;
			}
		}
		if (flag)
			if (temp>=-1000.0f&&temp<=1000.0f) {
				countt++;
				sum+=temp;
			}
			else printf("ERROR: %s is not a legal number\n",ss);
	}
	if (countt==1) printf("The average of 1 number is %.2lf\n",sum);
	else if (countt==0) printf("The average of 0 numbers is Undefined\n");
	else printf("The average of %d numbers is %.2lf\n",countt,sum/countt);
	return 0;
}
