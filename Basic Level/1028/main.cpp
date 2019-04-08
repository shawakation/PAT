/*
1.string.h中的函数专门为char数组型字符串设计
	会用这些函数：strcpy  strlen  strcmp
2.排序找最大最小，首先想到algorithm sort函数，
	要会自己写判断函数
3.scanf的按指定格式输入很有用
*/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
struct person
{
	char name[6];
	int year,month,day;
};
bool isold(struct person a,struct person b)
{
	if (a.year>b.year) return true;
	else if (a.year==b.year&&a.month>b.month) return true;
	else if (a.year==b.year&&a.month==b.month&&a.day>b.day) return true;
	else return false;
}
int main()
{
	int n,avail;
	cin>>n;
	avail=n;
	vector<person> arr;
	for (int i=0;i<n;i++) {
		char name[6];
		int year,month,day;
		scanf("%s %d/%d/%d",name,&year,&month,&day);
		if (year>2014||year<1814) {
			avail--;
			continue;
		}
		else if ((year==2014&&month>9)||(year==1814&&month<9)) {
			avail--;
			continue;
		}
		else if ((year==2014&&month==9&&day>6)||(year==1814&&month==9&&day<6)) {
			avail--;
			continue;
		}
		else {
			person temp;
			strcpy(temp.name,name);
			temp.year=year;
			temp.month=month;
			temp.day=day;
			arr.push_back(temp);
		}
	}
	sort(arr.begin(),arr.end(),isold);
	int countt=arr.size()-1;
	if (avail==0) cout<<0;
	else cout<<avail<<' '<<arr[countt].name<<' '<<arr[0].name;
	return 0;
}
