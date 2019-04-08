/*
难题，注意思路，找简便方法，尤其会用STL模版，模版套模版
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int rate[24];
struct record
{
	string name;
	int month,day,hour,minute;
	bool line;
};
bool cmp(struct record a,struct record b)   //注意点1：cmp的简便写法
{
	if (a.name!=b.name) return a.name<b.name;
	else if (a.month!=b.month) return a.month<b.month;
	else if (a.day!=b.day) return a.day<b.day;
	else if (a.hour!=b.hour) return a.hour<b.hour;
	else return a.minute<b.minute;
}
int main()
{
	for (int i=0;i<24;i++) scanf("%d",&rate[i]);
	int n;
	vector<record> arr;
	map<string,vector<record>> jieguo;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		record rec;
		string online;
		cin>>rec.name;
		scanf("%d:%d:%d:%d",&rec.month,&rec.day,&rec.hour,&rec.minute);
		cin>>online;
		if (online=="on-line") rec.line=1;
		else if (online=="off-line") rec.line=0;
		arr.push_back(rec);
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int k=0;k<arr.size()-1;k++) {
		if (arr[k].name==arr[k+1].name&&arr[k].month==arr[k+1].month&&arr[k].line==1&&arr[k+1].line==0) {
			jieguo[arr[k].name].push_back(arr[k]);
			jieguo[arr[k].name].push_back(arr[k+1]);
			k++;
		}
	}
	for (map<string,vector<record>>::iterator it=jieguo.begin();it!=jieguo.end();it++) {
		vector<record> temp(it->second);
		cout<<it->first<<' ';
		printf("%02d\n",temp[0].month);
		int allmoney=0;
		for (int k=0;k<temp.size();k+=2) {
			record start=temp[k],end=temp[k+1];
			printf("%02d:%02d:%02d %02d:%02d:%02d ",start.day,start.hour,start.minute,end.day,end.hour,end.minute);
			int totaltime=0,totalmoney=0;
			while (start.day<end.day||start.hour<end.hour||start.minute<end.minute) {
				totaltime++;
				totalmoney+=rate[start.hour];
				start.minute++;
				if (start.minute>=60) {
					start.minute=0;
					start.hour++;
				}
				if (start.hour>=24) {
					start.day++;
					start.hour=0;
				}
			}
			allmoney+=totalmoney;
			printf("%d $%.2lf\n",totaltime,totalmoney/100.0f);
		}
		printf("Total amount: $%.2lf\n",allmoney/100.0f);
	}
	return 0;
}
