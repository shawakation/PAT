#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string A,B;
	stack<unsigned short> Astack,Bstack;
	char DA,DB;
	cin>>A>>DA>>B>>DB;
	for (unsigned short i=0;i<A.length();i++)
		if (A[i]==DA) Astack.push((DA-'0'));
	for (unsigned short i=0;i<B.length();i++)
		if (B[i]==DB) Bstack.push((DB-'0'));
	unsigned short countA=0,countB=0;
	unsigned long sumA=0,sumB=0;
	while (!Astack.empty()) {
		unsigned short temp=Astack.top();
		Astack.pop();
		sumA+=(unsigned long)pow(10,countA++)*temp;
	}
	while (!Bstack.empty()) {
		unsigned short temp=Bstack.top();
		Bstack.pop();
		sumB+=(unsigned long)pow(10,countB++)*temp;
	}
	cout<<sumA+sumB<<endl;
	return 0;
}
