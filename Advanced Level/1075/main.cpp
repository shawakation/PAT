/*
the number of perfectly solved problems：
最后一个测试点注意：可能有用户提交多次得到满分，但完美解题只能算一次的
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct user
{
	int id;
	int t_score;
	int rank;
	int score[5];
	int perf_solv;
	bool isprint;
	user() {
		id=t_score=rank=perf_solv=0;
		isprint=0;
		for (int i=0;i<5;i++) score[i]=-1;
	}
};
bool cmp(struct user a,struct user b)
{
	if (a.t_score!=b.t_score) return a.t_score>b.t_score;
	else if (a.perf_solv!=b.perf_solv) return a.perf_solv>b.perf_solv;
	else return a.id<b.id;
}
int main()
{
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	vector<user> arr(n);
	for (int i=1;i<=n;i++) arr[i-1].id=i;
	int prob_grade[5]={0};
	for (int i=0;i<k;i++) scanf("%d",&prob_grade[i]);
	for (int i=0;i<m;i++) {
		int uid,pid,pscore;
		scanf("%d %d %d",&uid,&pid,&pscore);
		if (pscore==-1&&arr[uid-1].score[pid-1]==-1) arr[uid-1].score[pid-1]=0;
		else {
			arr[uid-1].isprint=1;
			if (pscore==prob_grade[pid-1]&&arr[uid-1].score[pid-1]<pscore) arr[uid-1].perf_solv++;
			if (arr[uid-1].score[pid-1]<pscore) {
				arr[uid-1].score[pid-1]=pscore;
				arr[uid-1].t_score=0;
				for (int s=0;s<k;s++) {
					if (arr[uid-1].score[s]>0) arr[uid-1].t_score+=arr[uid-1].score[s];
				}
			}
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	arr[0].rank=1;
	for (int i=0;i<arr.size();i++) {
		if (i>0) {
			if (arr[i].t_score==arr[i-1].t_score) arr[i].rank=arr[i-1].rank;
			else arr[i].rank=i+1;
		}
		if (arr[i].isprint) {
			printf("%d %05d %d",arr[i].rank,arr[i].id,arr[i].t_score);
			for (int s=0;s<k;s++) {
				if (arr[i].score[s]==-1) printf(" -");
				else printf(" %d",arr[i].score[s]);
			}
			printf("\n");
		}
	}
	return 0;
}
