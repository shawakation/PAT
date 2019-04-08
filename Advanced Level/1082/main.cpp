/*
1.用左右两个指针处理字符串的思想
2.四位一组，需要判断两种情况，一是非零数字前面有零，二是整个四位全是零
3.关于空格的处理，可以先输出空格，再输出必要数据，只令首位不输出空格即可，可以避免末尾多输出
4.这道题重打第二遍
*/
#include <iostream>
#include <string>
using namespace std;
string arr1[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string arr2[5]={"Shi","Bai","Qian","Wan","Yi"};
int main()
{
	string s;
	cin>>s;
	if (s=="0") {
		cout<<"ling";
		return 0;
	}
	if (s[0]=='-') {
		cout<<"Fu ";
		s.erase(0,1);
	}
	int a=0,b=s.length()-1;
	while (4<=b) b-=4;
	while (b<s.length()) {
		bool flag=0,isprint=0;
		while (a<=b) {
			if (s[a]=='0') flag=1;
			else {
				if (flag) {
					cout<<" ling";
					flag=0;
				}
				if (a>0) cout<<' ';
				cout<<arr1[s[a]-'0'];
				if (a!=b) cout<<' '<<arr2[b-a-1];
				isprint=1;
			}
			a++;
		}
		if (isprint) {
			int cha=(s.length()-1-b)/4;
			if (cha) cout<<' '<<arr2[cha+2];
		}
		b+=4;
	}
	return 0;
}
