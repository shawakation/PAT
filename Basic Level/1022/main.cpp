#include <iostream>
#include <stack>
using namespace std;
int main()
{
	unsigned long long A,B;
	short D;
	stack<unsigned short> remin;
	cin>>A>>B>>D;
	unsigned long long C=A+B;
	if (C==0) {
		cout<<0;
		return 0;
	}
	while (C!=0) {
		unsigned short reminder=C%D;
		remin.push(reminder);
		C=C/D;
	}
	while (!remin.empty()) {
		cout<<remin.top();
		remin.pop();
	}
	return 0;
}
