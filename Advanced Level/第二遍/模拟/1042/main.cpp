#include <bits/stdc++.h>
using namespace std;
int main()
{
	int k;
	scanf("%d",&k);
	vector<int> arr(55),order(55);
	for (int i=1;i<=54;i++) {
		scanf("%d",&order[i]);
		arr[i]=i;
	}
	for (int i=0;i<k;i++) {
		vector<int> overcome(55);
		for (int j=1;j<=54;j++) overcome[order[j]]=arr[j];
		arr=overcome;
	}
	for (int i=1;i<=54;i++) {
		int shang=(arr[i]-1)/13,yu=arr[i]%13;
		switch (shang) {
			case 0:{
				printf("S");
				break;
			}
			case 1:{
				printf("H");
				break;
			}
			case 2:{
				printf("C");
				break;
			}
			case 3:{
				printf("D");
				break;
			}
			case 4:{
				printf("J");
				break;
			}
		}
		if (yu==0) printf("13");
		else printf("%d",yu);
		if (i<54) printf(" ");
	}
	return 0;
}
