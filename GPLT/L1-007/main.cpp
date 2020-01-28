#include <iostream>
#include <string>
using namespace std;
string arr[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};
int main()
{
	string s;
	int countt=0;
	cin>>s;
	for (char &a:s) {
		if (a=='-') cout<<arr[10];
		else cout<<arr[a-'0'];
		countt++;
		if (countt<s.length()) cout<<' ';
	}
	cout<<'\n';
	return 0;
}
