#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,b;
	bool flag=1;
	vector<int> arr;
	cin>>n>>b;
	while (n) {
		int remander=n%b;
		arr.push_back(remander);
		n=n/b;
	}
	int c=arr.size();
	if (c==1) cout<<"Yes\n";
	else {
		for (int i=0;i<c/2;i++) {
			if (arr[i]!=arr[c-1-i]) {
				cout<<"No\n";
				flag=0;
				break;
			}
		}
		if (flag) cout<<"Yes\n";
	}
	for (int i=c-1;i>=0;i--) {
		cout<<arr[i];
		if (i>0) cout<<' ';
	}
	return 0;
}
