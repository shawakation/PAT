#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,s;
	scanf("%d%d%d",&m,&n,&s);
	vector<string> arr(m+1);
	unordered_set<string> isforward;
	for (int i=1;i<=m;i++) cin>>arr[i];
	for (int i=s;i<=m;) {
		if (isforward.find(arr[i])==isforward.end()) {
			cout<<arr[i]<<endl;
			isforward.insert(arr[i]);
			i+=n;
		}
		else i++;
	}
	if (isforward.size()==0) cout<<"Keep going...\n";
	return 0;
}
