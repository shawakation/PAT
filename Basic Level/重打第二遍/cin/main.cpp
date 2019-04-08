#include <iostream>
using namespace std;
int main()
{
	char a,b,c,d;
	for (int i=0;i<2;i++) cin>>a>>b;
	cin.ignore();
	c=cin.get();
	d=cin.get();
	cout<<a<<' '<<b<<' '<<c<<' '<<d;
	return 0;
}
