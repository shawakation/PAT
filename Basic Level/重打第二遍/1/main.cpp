#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	vector<int> arr;
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		string ss;
		getline(cin,ss,'\n');
		for (int j=0;j<ss.length();j++)
			if (ss[j]=='T') {
				j-=2;
				switch (ss[j]) {
					case 'A':{
						arr.push_back(1);
						break;
					}
					case 'B':{
						arr.push_back(2);
						break;
					}
					case 'C':{
						arr.push_back(3);
						break;
					}
					case 'D':{
						arr.push_back(4);
						break;
					}
				}
				break;
			}
	}
	for (int i=0;i<arr.size();i++) cout<<arr[i];
	return 0;
}
