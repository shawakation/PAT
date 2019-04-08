#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++) {
		int teacher;
		vector<int> scores;
		cin>>teacher;
		for (int j=0;j<n-1;j++) {
			int stu;
			cin>>stu;
			if (stu>=0&&stu<=m) scores.push_back(stu);
		}
		sort(scores.begin(),scores.end());
		int sum=0;
		for (int k=1;k<scores.size()-1;k++) sum+=scores[k];
		float average=(float)sum/(float)(scores.size()-2);
		int zong=round((average+(float)teacher)/2.0f);
		cout<<zong<<endl;
	}
	return 0;
}
