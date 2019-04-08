#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,k,score[101]={0};
	vector<int> aa;
	cin>>n;
	for (int i=0;i<n;i++) {
		int sco;
		cin>>sco;
		score[sco]++;
	}
	cin>>k;
	for (int i=0;i<k;i++) {
		int cha;
		cin>>cha;
		aa.push_back(score[cha]);
	}
	for (int i=0;i<aa.size();i++) {
		cout<<aa[i];
		if (i!=aa.size()-1) cout<<' ';
	}
	return 0;
}
