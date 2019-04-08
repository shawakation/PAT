#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int c=0;
struct stu
{
	string id;
	string name;
	int grade;
};
bool cmp(struct stu a,struct stu b)
{
	if (c==1) {
		return a.id<b.id;
	}
	else if (c==2) {
		if (a.name!=b.name) return a.name<b.name;
		else return a.id<b.id;
	}
	else if (c==3) {
		if (a.grade!=b.grade) return a.grade<b.grade;
		else return a.id<b.id;
	}
}
int main()
{
	int n;
	vector<stu> arr;
	scanf("%d %d",&n,&c);
	for (int i=0;i<n;i++) {
		stu aa;
		cin>>aa.id>>aa.name;
		scanf("%d",&aa.grade);
		arr.push_back(aa);
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<arr.size();i++) {
		cout<<arr[i].id<<' '<<arr[i].name;
		printf(" %d\n",arr[i].grade);
	}
	return 0;
}
