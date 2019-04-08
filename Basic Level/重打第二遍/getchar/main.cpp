#include <vector>
#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<vector<int>> arr(n);
	vector<int> qq(n);
	for (int i=0;i<n;i++) cin>>qq[i];
	for (int i=0;i<n;i++) arr[i]=qq;
	for (int i=0;i<n;i++) cout<<arr[3][i]<<' ';
	return 0;
}
