/*
有三个样例超时还未解决
1.C++ class的写法  构造函数
2.定义vector数组的方法  vector<int> v[n];
3.algorithm sort 函数，会写结构体或类的排序函数
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class kaosheng
{
	public:
		int number;
		int de;
		int cai;
		int total;
	public:
		kaosheng(int a,int b,int c)
		{
			this->number=a;
			this->de=b;
			this->cai=c;
			this->total=b+c;
		}
};
bool cmp(class kaosheng a,class kaosheng b)
{
	if (a.total==b.total) {
		if (a.de==b.de) return a.number<b.number;
		else return a.de>b.de;
	}
	else return a.total>b.total;
}
int main()
{
	int n,l,h,sum=0;
	vector<kaosheng> vv[4];
	cin>>n>>l>>h;
	for (int i=0;i<n;i++) {
		int num,de,cai;
		cin>>num>>de>>cai;
		if (de>=l&&cai>=l) {
			kaosheng aa(num,de,cai);
			if (de>=h&&cai>=h) vv[0].push_back(aa);
			else if (de>=h&&cai<h) vv[1].push_back(aa);
			else if (de<h&&cai<h&&de>=cai) vv[2].push_back(aa);
			else vv[3].push_back(aa);
		}
	}
	for (int i=0;i<4;i++) sort(vv[i].begin(),vv[i].end(),cmp);
	for (int i=0;i<4;i++) sum+=vv[i].size();
	cout<<sum<<endl;
	for (int j=0;j<4;j++)
		for (int i=0;i<vv[j].size();i++)
			cout<<vv[j][i].number<<' '<<vv[j][i].de<<' '<<vv[j][i].cai<<endl;
	return 0;
}
