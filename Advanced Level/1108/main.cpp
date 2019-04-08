#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,countt=0;
	double sum=0.0;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		char num[100],num2[100];
		double real;
		scanf("%s",num);
		sscanf(num,"%lf",&real);
		sprintf(num2,"%.2f",real);
		int len=strlen(num);
		bool flag=0;
		for (int j=0;j<len;j++) if (num[j]!=num2[j]) {
			flag=1;
			break;
		}
		if (flag||real>1000||real<-1000) {
			printf("ERROR: %s is not a legal number\n",num);
			continue;
		}
		else {
			sum+=real;
			countt++;
		}
	}
	if (countt==0) printf("The average of 0 numbers is Undefined\n");
	else if (countt==1) printf("The average of 1 number is %.2f\n",sum);
	else printf("The average of %d numbers is %.2f\n",countt,sum/countt);
	return 0;
}
