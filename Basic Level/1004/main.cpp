/*
其实可以用algorithm sort来做
*/
#include <iostream>
using namespace std;
struct Student
{
	char name[11];
	char num[11];
	unsigned short mark;
};
int main()
{
	unsigned long n;
	cin>>n;
	Student *stu=new Student[n];
	for (unsigned short k=0;k<n;k++)
		cin>>stu[k].name>>stu[k].num>>stu[k].mark;
	Student maxmark=stu[0];
	Student minmark=stu[0];
	for (unsigned short k=1;k<n;k++)
		if (stu[k].mark>maxmark.mark) maxmark=stu[k];
	for (unsigned short k=1;k<n;k++)
		if (stu[k].mark<minmark.mark) minmark=stu[k];
	cout<<maxmark.name<<' '<<maxmark.num<<endl;
	cout<<minmark.name<<' '<<minmark.num<<endl;
	return 0;
}
