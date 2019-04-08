#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,minl=300,j,i;
	vector<string> arr;
	cin>>n;
	cin.ignore();
	for (int i=0;i<n;i++) {
		string s;
		getline(cin,s,'\n');
		if (s.length()<minl) minl=s.length();
		reverse(s.begin(),s.end());
		arr.push_back(s);
	}
	for (j=0;j<minl;j++)
		for (i=0;i<n-1;i++) {
			if (arr[i][j]!=arr[i+1][j]) goto aa;
		}
	aa:if (j) {
		string s1=arr[0].substr(0,j);
		reverse(s1.begin(),s1.end());
		cout<<s1;
	}
	else cout<<"nai";
	return 0;
}
