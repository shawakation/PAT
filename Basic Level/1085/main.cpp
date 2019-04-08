/*
1.map容器的用法：例：map<string,int>  string为索引，int为数值
    直接用索引作下标访问，若无，则加入并设初始值
    若有，则直接对对应数据值进行操作
2.用迭代器访问下标的用法：设it   it->first为map<string,int>中的string
								 it->second为map<string,int>中的int
3.cctype中函数的用法：isalpha  isdigit  isalnum  isblank  isupper islower  toupper  tolower
*/
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;
struct schools
{
	string name;
	int gradess;
	int kaoshengs;
};
bool cmp(struct schools a,struct schools b)
{
	if (a.gradess!=b.gradess) return  a.gradess>b.gradess;
	else {
		if (a.kaoshengs!=b.kaoshengs) return a.kaoshengs<b.kaoshengs;
		else return a.name<b.name;
	}
}
int main()
{
	int n;
	map<string,int> kaoshengnum;
	map<string,float> grades;
	cin>>n;
	for (int i=0;i<n;i++) {
		string num;
		int grade;
		string school;
		cin>>num>>grade>>school;
		for (int i=0;i<school.length();i++)
			if (isupper(school[i])) school[i]=tolower(school[i]);
		kaoshengnum[school]++;
		if (num[0]=='B') grades[school]+=(float)grade/1.5f;
		else if (num[0]=='A') grades[school]+=(float)grade;
		else if (num[0]=='T') grades[school]+=(float)grade*1.5f;
	}
	int countt=kaoshengnum.size();
	cout<<countt<<endl;
	vector<schools> vv;
	map<string,float>::iterator it2=grades.begin();
	for (map<string,int>::iterator it=kaoshengnum.begin();it!=kaoshengnum.end();it++) {
		schools aschool;
		aschool.name=it->first;
		aschool.kaoshengs=it->second;
		aschool.gradess=(int)(it2->second);
		vv.push_back(aschool);
		it2++;
	}
	sort(vv.begin(),vv.end(),cmp);
	bool flag=true;
	int aa=0;
	for (int i=0,i1=0;i<vv.size();i++) {
		if (flag) cout<<i+1;
		else cout<<i1+1;
		cout<<' '<<vv[i].name<<' '<<vv[i].gradess<<' '<<vv[i].kaoshengs<<endl;
		if (vv[i].gradess==vv[i+1].gradess) flag=false;
		else {
			flag=true;
			i1=i+1;
		}
	}
	return 0;
}
