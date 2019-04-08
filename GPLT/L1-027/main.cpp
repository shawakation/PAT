#include <bits/stdc++.h>
using namespace std;
struct comp
{
	bool operator () (int a,int b) const {
		return a>b;
	}
};
set<int,comp> my;
unordered_map<int,int> relation;
int main()
{
	char num[12];
	scanf("%s",num);
	for (int i=0;i<11;i++) my.insert(num[i]-'0');
	int i=0,index[11];
	for (auto &p:my) relation[p]=i++;
	for (int j=0;j<11;j++) index[j]=relation[num[j]-'0'];
	printf("int[] arr = new int[]{");
	for (auto &p:my) {
		printf("%d",p);
		i--;
		if (i>0) printf(",");
	}
	printf("};\n");
	printf("int[] index = new int[]{");
	for (int j=0;j<11;j++) {
		printf("%d",index[j]);
		if (j<10) printf(",");
	}
	printf("};\n");
	return 0;
}
