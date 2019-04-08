/*
1.注意范围，很难注意到。。。。
*/
#include <bits/stdc++.h>
using namespace std;
string weeks[]={"##","MON","TUE","WED","THU","FRI","SAT","SUN"};
int main()
{
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int i=0,len=min(a.length(),b.length()),len2=min(c.length(),d.length());
	for (;i<len;i++) if (a[i]==b[i]&&a[i]>='A'&&a[i]<='G') break;
	int week=a[i]-'A'+1;
	for (i++;i<len;i++) if (a[i]==b[i]&&(isdigit(a[i])||a[i]>='A'&&a[i]<='N')) break;
	int hour=(isalpha(a[i]))?(a[i]-'A'+10):(a[i]-'0');
	for (i=0;i<len2;i++) if (c[i]==d[i]&&isalpha(c[i])) break;
	printf("%s %02d:%02d",weeks[week].c_str(),hour,i);
	return 0;
}
