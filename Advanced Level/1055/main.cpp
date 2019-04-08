#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
struct person
{
	char name[10];
	int age;
	int worth;
};
bool cmp(struct person a,struct person b)
{
	if (a.worth!=b.worth) return a.worth>b.worth;
	else if (a.age!=b.age) return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}
int main()
{
	int n,k;
	vector<person> arr;
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++) {
		person aa;
		scanf("%s %d %d",aa.name,&aa.age,&aa.worth);
		arr.push_back(aa);
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<k;i++) {
		int maxout,agemin,agemax;
		bool flag=1;
		scanf("%d %d %d",&maxout,&agemin,&agemax);
		printf("Case #%d:\n",i+1);
		for (int j=0;j<arr.size()&&maxout;j++) {
			if (arr[j].age>=agemin&&arr[j].age<=agemax) {
				printf("%s %d %d\n",arr[j].name,arr[j].age,arr[j].worth);
				flag=0;
				maxout--;
			}
		}
		if (flag) printf("None\n");
	}
	return 0;
}
