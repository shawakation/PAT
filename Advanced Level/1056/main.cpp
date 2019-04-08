#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main()
{
	int np,ng;
	deque<vector<int> > que;
	scanf("%d%d",&np,&ng);
	vector<int> mass(np),order(np);
	for (int i=0;i<np;i++) scanf("%d",&mass[i]);
	for (int i=0;i<np;i++) scanf("%d",&order[i]);
	vector<int> temp(np);
	for (int i=0;i<np;i++) temp[i]=mass[order[i]];
	while (temp.size()>1) {
		vector<int> winner,loser;
		for (int i=0;i<temp.size();i+=ng) {
			auto maxx=max_element(temp.begin()+i,temp.begin()+min((int)temp.size(),i+ng));
			int maxcur=maxx-temp.begin();
			for (int g=i;g<min((int)temp.size(),i+ng);g++) {
				if (g==maxcur) winner.push_back(temp[g]);
				else loser.push_back(temp[g]);
			}
		}
		que.push_front(loser);
		temp.assign(winner.begin(),winner.end());
	}
	que.push_front(temp);
	unordered_map<int,int> ranks;
	int rankt=1;
	for (auto &p:que) {
		for (auto &l:p) ranks[l]=rankt;
		rankt+=p.size();
	}
	for (int i=0;i<np;i++) {
		printf("%d",ranks[mass[i]]);
		if (i<np-1) printf(" ");
	}
	printf("\n");
	return 0;
}
