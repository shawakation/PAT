/*
1.≥¨ ±¡À
*/
#include <string>
#include <iostream>
#include <cctype>
using namespace std;
int main()
{
	string ss;
	unsigned long sum=0;
	unsigned int count1=0,count0=0;
	getline(cin,ss,'\n');
	for (unsigned short i=0;i<ss.size();i++)
		if (isalpha(ss[i])) sum+=(toupper(ss[i])-'A'+1);
	while (sum!=0) {
		if (sum%2==1) count1++;
		else if (sum%2==0) count0++;
		sum=sum/2;
	}
	cout<<count0<<' '<<count1;
	return 0;
}
