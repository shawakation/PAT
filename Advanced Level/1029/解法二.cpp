#include <iostream>
using namespace std;
const int maxn=100006;
int s1[maxn]= {0},s2[maxn]= {0};
int main()
{
	int n1,n2;
	scanf("%d",&n1);
	for (int i=0; i<n1; i++) {
		scanf("%ld",&s1[i]);
	}
	scanf("%d",&n2);
	for (int i=0; i<n2; i++) {
		scanf("%ld",&s2[i]);
	}
	int countt=(n1+n2-1)/2,i=0,j=0;
	while (countt>0&&i<n1&&j<n2) {
		if (s1[i]<s2[j]) i++;
		else if (s1[i]>s2[j]) j++;
		countt--;
	}
	while (countt>0&&i<n1) {
		i++;
		countt--;
	}
	while (countt>0&&j<n2) {
		j++;
		countt--;
	}
	if (s1[i]<s2[j]) printf("%ld",s1[i]);
	else printf("%ld",s2[j]);
	return 0;
}
