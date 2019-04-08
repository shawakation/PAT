#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int N=s.length();
	int n1=(N-1)/3;
	int n2=N-2*n1;
	for (int i=0;i<n1;i++) {
		cout<<s[i];
		for (int j=0;j<n2-2;j++) cout<<' ';
		cout<<s[N-1-i];
		cout<<endl;
	}
	cout<<s.substr(n1,n2)<<endl;
	return 0;
}
