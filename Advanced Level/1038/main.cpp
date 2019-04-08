/*
1.思路  看不懂。。。。
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(string a,string b)
{
	return a+b<b+a;
}
int main()
{
	int n;
	string ans;
	scanf("%d",&n);
	vector<string> arr(n);
	for (int i=0; i<n; i++) cin>>arr[i];
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0; i<n; i++) ans+=arr[i];
	while (ans.length()>0&&ans[0]=='0') ans.erase(0,1);
	if (ans.length()==0) printf("0");
	else cout<<ans;
	return 0;
}
