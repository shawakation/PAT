#include <iostream>
#include <string>
using namespace std;
string convert(int a)
{
	string s="";
	if (a==0) {
		s+="00";
		return s;
	}
	while (a) {
		int remander=a%13;
		if (remander<10) s.insert(s.begin(),remander+'0');
		else switch (remander) {
			case 10:{
				s.insert(s.begin(),'A');
				break;
			}
			case 11:{
				s.insert(s.begin(),'B');
				break;
			}
			case 12:{
				s.insert(s.begin(),'C');
				break;
			}
		}
		a/=13;
	}
	if (s.length()==1) s.insert(s.begin(),'0');
	return s;
}
int main()
{
	int R,G,B;
	scanf("%d %d %d",&R,&G,&B);
	string R1=convert(R);
	string G1=convert(G);
	string B1=convert(B);
	cout<<'#'<<R1<<G1<<B1;
	return 0;
}
