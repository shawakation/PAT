/*
1.cctype的几个函数：
		isalnum  isalpha  isdigit  isblank  isupper  islower  toupper  tolower
2.string可以用数组定义，按数组下标的方式访问，每个元素是一个string
		string[2][3]
*/
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	string a,b,c,d;
	int i=0;
	string weeks[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	cin>>a>>b>>c>>d;
	int lens=a.length()>b.length()?b.length():a.length();
	int lens2=c.length()>d.length()?d.length():c.length();
	for (;i<lens;i++) {
		if (a[i]==b[i]&&(a[i]>='A'&&a[i]<='G')) {
			int week=a[i]-'A';
			cout<<weeks[week]<<' ';
			i++;
			break;
		}
	}
	for (;i<lens;i++) {
		if (a[i]==b[i]&&(a[i]>='A'&&a[i]<='N'||isdigit(a[i]))) {
			int hour;
			if (isdigit(a[i])) hour=a[i]-'0';
			else if (isalpha(a[i])) hour=a[i]-'A'+10;
			printf("%02d",hour);
			break;
		}
	}
	for (int j=0;j<lens2;j++) {
		if (c[j]==d[j]&&isalpha(c[j])) {
			printf(":%02d",j);
			break;
		}
	}
	return 0;
}
