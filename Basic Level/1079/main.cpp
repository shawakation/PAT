/*
1.stringstream类可以转换为int  unsigned long long 等数字型
        要会string和数字间的转换
2.cin输入无符号数可以直接输，但scanf输入需要加入控制格式符%u，用%d会错误
*/
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
unsigned long long stringtoint(string s)
{
	stringstream strr(s);
	unsigned long long aa;
	strr>>aa;
	return aa;
}
bool ishuiwenshu(unsigned long long n)
{
	string temp=to_string(n);
	int k=temp.length()-1;
	for (int i=0;i<=k/2;i++) {
		if (temp[i]!=temp[k-i]) return false;
	}
	return true;
}
int main()
{
	unsigned long long n;
	int countt=1;
	cin>>n;
	while (countt<=10) {
		if (ishuiwenshu(n)) {
			cout<<n<<" is a palindromic number.\n";
			return 0;
		}
		else {
			string num=to_string(n);
			reverse(num.begin(),num.end());
			unsigned long long nre=stringtoint(num);
			cout<<n<<" + "<<num<<" = ";
			n+=nre;
			cout<<n<<endl;
			countt++;
		}
	}
	cout<<"Not found in 10 iterations.\n";
	return 0;
}
