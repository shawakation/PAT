/*
启发：数组用vector代替可能会好一些，尤其是要用到algorithm的时候
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,seat=1;
	cin>>n;
	vector<vector<int>> arr;
	vector<int> countt(n);
	int max=0;
	for (int i=0;i<n;i++) {
		int a;
		cin>>a;
		if (a>max) max=a;
		vector<int> b(a*10);
		arr.push_back(b);
	}
	int flag=0;
	for (int i=0;i<max*10;i++) {
		for (int j=0;j<n;j++) {
			if (countt[j]==0) {
				if (i<arr[j].size()) {
					if (flag==0) arr[j][i]=seat++;
					else if (flag==1) {
						arr[j][i]=seat;
						seat+=2;
					}
				}
				else if (i>=arr[i].size()) countt[j]=1;
			}
		}
		if (flag==0) {
			int q=count(countt.begin(),countt.end(),1);
			if (q==n-1) {
				flag=1;
				seat++;
			}
		}
	}
	for (int i=0;i<arr.size();i++) {
		cout<<"#"<<i+1<<endl;
		for (int j=0;j<arr[i].size();j++) {
			cout<<arr[i][j];
			if ((j+1)%10==0) cout<<endl;
			else cout<<' ';
		}
	}
	return 0;
}
