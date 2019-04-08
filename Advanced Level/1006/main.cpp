/*
不是最优代码，其实可以边输入边比较！
*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct time
{
	int hour,minu,seco;
};
struct person
{
	string num;
	struct time in;
	struct time out;
	person(string a,struct time b,struct time c) {
		num=a;
		in=b;
		out=c;
	}
};
bool cmp1(struct person a,struct person b)
{
	if (a.in.hour==b.in.hour) {
		if (a.in.minu==b.in.minu) return a.in.seco<b.in.seco;
		else return a.in.minu<b.in.minu;
	}
	else return a.in.hour<b.in.hour;
}
bool cmp2(struct person a,struct person b)
{
	if (a.out.hour==b.out.hour) {
		if (a.out.minu==b.out.minu) return a.out.seco>b.out.seco;
		else return a.out.minu>b.out.minu;
	}
	else return a.out.hour>b.out.hour;
}
int main()
{
	int n;
	vector<person> arr;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		string name;
		struct time in1;
		struct time out1;
		cin>>name;
		scanf("%d:%d:%d %d:%d:%d",&in1.hour,&in1.minu,&in1.seco,&out1.hour,&out1.minu,&out1.seco);
		person temp(name,in1,out1);
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end(),cmp1);
	cout<<arr[0].num<<' ';
	sort(arr.begin(),arr.end(),cmp2);
	cout<<arr[0].num;
	return 0;
}
