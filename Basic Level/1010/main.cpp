/*
1.在没有给出输入个数的情况下循环输入的问题：
	while (cin>>a>>n)
*/
#include <iostream>
using namespace std;
int main()
{
	short a,n;
	cin>>a>>n;
	if (n!=0) cout<<a*n<<' '<<n-1;
	else cout<<"0 0";
	while (cin>>a>>n) {
		if (n!=0)
			cout<<' '<<a*n<<' '<<n-1;
	}
	return 0;
}
