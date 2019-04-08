#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
int main()
{
	string A="",B="",Co="";
	cin>>A>>B;
	short cha=A.length()-B.length();
	if (cha>0) for (short i=cha;i>0;i--) B.insert(0,"0");
	else if (cha<0) for (short i=abs(cha);i>0;i--) A.insert(0,"0");
	for (short i=A.length()-1;i>=0;i--)
		if ((i+1)%2==0) {
			short chacha=B[i]-A[i];
			if (chacha<0) chacha+=10;
			switch (chacha) {
				case 10:{
					Co.insert(0,"J");
					break;
				}
				case 11:{
					Co.insert(0,"Q");
					break;
				}
				case 12:{
					Co.insert(0,"K");
					break;
				}
				default:{
					char temp=chacha+'0';
					stringstream sstr;
					sstr<<temp;
					Co.insert(0,sstr.str());
					break;
				}
			}
		}
		else {
			short chacha=(B[i]-'0'+(A[i]-'0'))%13;
			switch (chacha) {
				case 10:{
					Co.insert(0,"J");
					break;
				}
				case 11:{
					Co.insert(0,"Q");
					break;
				}
				case 12:{
					Co.insert(0,"K");
					break;
				}
				default:{
					char temp=chacha+'0';
					stringstream sstr;
					sstr<<temp;
					Co.insert(0,sstr.str());
					break;
				}
			}
		}
	cout<<Co;
	return 0;
}
