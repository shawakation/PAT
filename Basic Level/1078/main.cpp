/*
1.string与int相互转化的方法：
	1.to_string()函数（不知道哪个头文件里的）（用不了就换）
	2.stoi string转int
	3.stringstream类（经典方法）
2.输入带空格的字符串：getline函数
    注：getline之前用了cin后须在cin后调用ignore函数
3.string类自带的一些方法：insert  erase  substr  c_str
	insert函数的插入：插入string时位置只能用int下标表示
	                    插入单个字符时位置可以用iterator表示
*/
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
int strtoint(string s)
{
	stringstream str(s);
	int temp;
	str>>temp;
	return temp;
}
string inttostr(int a)
{
	stringstream str;
	str<<a;
	return str.str();
}
string compress(string s)
{
	string aa="";
	for (int i=0;i<s.length();) {
		int k=i+1;
		while (s[k]==s[i]&&k<s.length()) k++;
		if (k-i==1) {
			aa.insert(aa.end(),s[i]);
			i++;
		}
		else if (k-i>1) {
			aa.insert(aa.size(),inttostr(k-i));
			aa.insert(aa.end(),s[i]);
			i=k;
		}
	}
	return aa;
}
string uncompress(string s)
{
	string aa="";
	for (int i=0;i<s.length();) {
		if (isdigit(s[i])) {
			int k=i+1;
			while (isdigit(s[k])) k++;
			int num=strtoint(s.substr(i,k-i));
			aa.insert(aa.end(),num,s[k]);
			i=k+1;
		}
		else if (isalpha(s[i])||isblank(s[i])) {
			aa.insert(aa.end(),s[i]);
			i++;
		}
	}
	return aa;
}
int main()
{
	char a;
	string ss;
	cin>>a;
	cin.ignore();
	getline(cin,ss,'\n');
	if (a=='C') cout<<compress(ss)<<endl;
	else if (a=='D') cout<<uncompress(ss)<<endl;
	return 0;
}
