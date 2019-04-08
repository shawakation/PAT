#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct stu
{
	char name[11];
	char id[11];
	int grade;
};
bool cmp(struct stu a,struct stu b)
{
	return a.grade>b.grade;
}
int main()
{
	int grade1,grade2;
	long n;
	vector<stu> arr;
	scanf("%ld",&n);
	for (long i=0;i<n;i++) {
		stu aa;
		scanf("%s %s %d",aa.name,aa.id,&aa.grade);
		arr.push_back(aa);
	}
	sort(arr.begin(),arr.end(),cmp);
	scanf("%d %d",&grade1,&grade2);
	bool flag=1;
	for (long i=0;i<arr.size();i++) {
		if (arr[i].grade>=grade1&&arr[i].grade<=grade2) {
			printf("%s %s\n",arr[i].name,arr[i].id);
			flag=0;
		}
	}
	if (flag) printf("NONE\n");
	return 0;
}
