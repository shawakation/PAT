#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int k;
	vector<int> seq(55);
	vector<int> seq2(55);
	scanf("%d",&k);
	for (int i=1;i<=54;i++) {
		scanf("%d",&seq[i]);
		seq2[i]=i;
	}
	for (int i=0;i<k;i++) {
		vector<int> seq3(55);
		for (int j=1;j<=54;j++) seq3[seq[j]]=seq2[j];
		seq2.assign(seq3.begin(),seq3.end());
	}
	for (int i=1;i<=54;i++) {
		if (seq2[i]==54) printf("J2");
		else if (seq2[i]==53) printf("J1");
		else {
			int aa=(seq2[i]-1)/13;
			switch (aa) {
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
			}
			int bb=(seq2[i]-1)%13+1;
			printf("%d",bb);
		}
		if (i!=54) printf(" ");
	}
	return 0;
}
