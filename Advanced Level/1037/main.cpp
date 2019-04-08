/*
1.³¬Ê±
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int Nc,Np;
	long long money=0;
	vector<long long> Cou,Pro;
	scanf("%d",&Nc);
	for (int i=0;i<Nc;i++) {
		long long t;
		scanf("%lld",&t);
		Cou.push_back(t);
	}
	scanf("%d",&Np);
	for (int i=0;i<Np;i++) {
		long long t;
		scanf("%lld",&t);
		Pro.push_back(t);
	}
	sort(Cou.begin(),Cou.end());
	sort(Pro.begin(),Pro.end());
	for (int i=0;i<Cou.size()&&i<Pro.size()&&Cou[i]<0&&Pro[i]<0;i++)
		money+=Cou[i]*Pro[i];
	for (int i=Cou.size()-1,j=Pro.size()-1;i>=0&&j>=0&&Cou[i]>0&&Pro[j]>0;i--,j--)
		money+=Cou[i]*Pro[j];
	printf("%lld\n",money);
	return 0;
}
