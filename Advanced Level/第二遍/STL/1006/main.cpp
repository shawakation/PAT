#include <bits/stdc++.h>
using namespace std;
struct timet
{
	int hour,minute,second;
	friend bool operator < (const timet &a,const timet &b) {
		if (a.hour!=b.hour) return a.hour<b.hour;
		else if (a.minute!=b.minute) return a.minute<b.minute;
		else return a.second<b.second;
	}
};
struct person
{
	string id;
	timet in,off;
};
bool flag=1;
bool cmp(const person &a,const person &b)
{
	if (flag) return a.in<b.in;
	else return a.off<b.off;
}
int main()
{
	int m;
	vector<person> arr;
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		person tt;
		cin>>tt.id;
		scanf("%d:%d:%d %d:%d:%d",&tt.in.hour,&tt.in.minute,&tt.in.second,&tt.off.hour,&tt.off.minute,&tt.off.second);
		arr.push_back(tt);
	}
	sort(arr.begin(),arr.end(),cmp);
	string ans1=arr.begin()->id;
	flag=0;
	sort(arr.begin(),arr.end(),cmp);
	string ans2=arr.rbegin()->id;
	cout<<ans1<<' '<<ans2;
	return 0;
}
