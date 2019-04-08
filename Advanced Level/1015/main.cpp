/*
题意没读明白。。。。
*/
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string inttostr(int a)
{
	stringstream ss;
	ss<<a;
	return ss.str();
}
int strtoint(string s)
{
	stringstream ss(s);
	int a;
	ss>>a;
	return a;
}
bool isprime(int n)
{
	if (n<2) return 0;
	for (int i=2;i<=(int)sqrt(n);i++)
		if (n%i==0) return 0;
	return 1;
}
int main()
{
	int n,d;
	while (1) {
		scanf("%d",&n);
		if (n<0) break;
		scanf("%d",&d);
		if (d==10) {
			bool flag=1;
			if (!isprime(n)) {
				printf("No\n");
				flag=0;
			}
			if (flag) {
				string s1=inttostr(n);
				reverse(s1.begin(),s1.end());
				n=strtoint(s1);
				if (isprime(n)) printf("Yes\n");
				else printf("No\n");
			}
		}
		else {
			bool flag=1;
			if (!isprime(n)) {
				printf("No\n");
				flag=0;
			}
			if (flag) {
				string n1="";
				int n2=0;
				do {
					int remander=n%d;
					n1.insert(n1.begin(),remander+'0');
					n/=d;
				}while (n);
				reverse(n1.begin(),n1.end());
				for (int k=n1.length()-1;k>=0;k--) n2+=(n1[k]-'0')*pow(d,n1.length()-k-1);
				if (isprime(n2)) printf("Yes\n");
				else printf("No\n");
			}
		}
	}
	return 0;
}
