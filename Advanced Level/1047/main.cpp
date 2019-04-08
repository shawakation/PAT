/*
1.直接用 unordered_map 会超时
2.用 set 存不知为啥答案错误且在超时边缘，可能 set 排序效率比较低
3.最优解：用 vector algorithm 排序，开大 vector 数组
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define maxn 40010
#define maxk 2505
using namespace std;
char names[maxn][5]= {'\0'};
vector<int> my[maxk];
bool cmp(int a,int b)
{
	return strcmp(names[a],names[b])<0;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for (int i=0; i<n; i++) {
		int c;
		scanf("%s",names[i]);
		scanf("%d",&c);
		for (int j=0; j<c; j++) {
			int id;
			scanf("%d",&id);
			my[id].push_back(i);
		}
	}
	for (int i=1; i<=k; i++) {
		int s=my[i].size();
		printf("%d %d\n",i,s);
		if (s>0) {
			sort(my[i].begin(),my[i].end(),cmp);
			for (auto it:my[i]) printf("%s\n",names[it]);
		}
	}
	return 0;
}
