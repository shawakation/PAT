#include <iostream>
#include <string>
using namespace std;
int main()
{
	unsigned short n;
	cin>>n;
	cin.ignore();		//在getline前面的cin加上ignore以使其空格不被读取 
	short *arr=new short[n];
	for (unsigned short i=0;i<n;i++) {
		string ss;
		getline(cin,ss,'\n');
		short j=0;
		for (short k=0;k<ss.length();k++)
			if (ss[k]=='T') {
				j=k-2;
				break;
			}
		switch (ss[j]) {
			case 'A':{
				arr[i]=1;
				break;
			}
			case 'B':{
				arr[i]=2;
				break;
			}
			case 'C':{
				arr[i]=3;
				break;
			}
			case 'D':{
				arr[i]=4;
				break;
			}
		}
	}
	for (unsigned short i=0;i<n;i++) cout<<arr[i];
	return 0;
}
