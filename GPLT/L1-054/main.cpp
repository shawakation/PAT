#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	char a;
	int b;
	vector<string> arr;
	cin>>a>>b;
	cin.ignore();
	for (int i=0;i<b;i++) {
		string ss;
		getline(cin,ss,'\n');
		for (int aa=0;aa<ss.length();aa++)
			if (ss[aa]!=' ') ss[aa]=a;
		reverse(ss.begin(),ss.end());
		arr.push_back(ss);
	}
	bool flag=true;
	for (int i=0;i<b/2;i++) {
		if (arr[i]!=arr[b-i-1]) {
			flag=false;
			break;
		}
	}
	if (flag) cout<<"bu yong dao le\n";
	for (int i=arr.size()-1;i>=0;i--) cout<<arr[i]<<endl;
	return 0;
}
