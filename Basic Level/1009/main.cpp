#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str="";
	getline(cin,str,'\n');
	if (str=="") {
		return 0;
	}
	for (short i=str.length()-1;i>=0;i--) {
		if (str[i]==' ') {
			for (short j=i+1;j<str.length()&&str[j]!=' ';j++)
				cout<<str[j];
			cout<<' ';
			}
		if (i==0)
			for (short j=i;str[j]!=' '&&j<str.length();j++) cout<<str[j];
		}
	return 0;
}
