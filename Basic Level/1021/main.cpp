/*
1.数组初始化为某一初值：int arr[10]={0};
						char arr[10]={'\0'}
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	unsigned short arr[10]={0};
	cin>>str;
	for (unsigned short k=0;k<str.length();k++)
		arr[str[k]-'0']++;
	for (unsigned short k=0;k<10;k++)
		if (arr[k]!=0) cout<<k<<":"<<arr[k]<<endl;
	return 0;
}
