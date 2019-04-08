#include <bits/stdc++.h>
using namespace std;
struct stu
{
	public:
		string name;
		int Gp;
		int Gmid;
		int Gfinal;
		int G;
	public:
		stu()
		{
			name="";
			Gp=-1;
			Gmid=-1;
			Gfinal=-1;
			G=-1;
		}
	
};
bool cmp(struct stu a,struct stu b)
{
	return (a.G==b.G)?(a.name<b.name):(a.G>b.G);
}
int main()
{
	int p,m,n;
	map<string,stu> my;
	cin>>p>>m>>n;
	for (int i=0;i<p;i++) {
		string name;
		int score;
		cin>>name>>score;
		my[name].Gp=score;
	}
	for (int i=0;i<m;i++) {
		string name;
		int score;
		cin>>name>>score;
		my[name].Gmid=score;
	}
	for (int i=0;i<n;i++) {
		string name;
		int score;
		cin>>name>>score;
		my[name].Gfinal=score;
		float zong;
		if (my[name].Gmid>score) zong=(float)my[name].Gmid*0.4+(float)score*0.6;
		else zong=(float)score;
		my[name].G=round(zong);
	}
	vector<stu> arr;
	for (map<string,stu>::iterator p=my.begin();p!=my.end();p++) {
		if ((p->second).Gp>=200&&(p->second).G>=60) {
			stu temp=p->second;
			temp.name=p->first;
			arr.push_back(temp);
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<arr.size();i++)
		cout<<arr[i].name<<' '<<arr[i].Gp<<' '<<arr[i].Gmid<<' '<<arr[i].Gfinal<<' '<<arr[i].G<<endl;
	return 0;
}
