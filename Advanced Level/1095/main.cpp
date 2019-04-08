/*
1.注意输入结构体中的数据时不要忘记加 &，scanf 仔细检查！！
2.time好像是关键词，定义成结构体要在前面加 struct ，或者直接改timet
    可能是关键词的要有意识在后面加个t
3.时间转换：可以以00:00:00为初始，全部转化为秒，
            但要注意转换回来的函数，千万别马虎写错了！！！！
4.隐蔽的陷阱：查询时 进来时间==查询时间 算在里面
                但是  出去时间==查询时间  不能算在里面
5.太马虎了：计算总时间写到了查询里面导致每个plate都出现了k次！
6.超时问题：
	(1)把计算最大时间与分类合法数据合并
	(2)注意查询时间为递增，因此可以设置标记now，查完一个就把now设置为查完的数组下标
	    前提是合法记录要按time排序
7.快速转换时间：学习了
	printf("%02d:%02d:%02d", maxtime / 3600, (maxtime % 3600) / 60, maxtime % 60);
8.printf 输出 string 的方法：
	string ss;
	printf("%s",ss.c_str());
scanf 输入字符串的方法：
	char s1[10];
	scanf("%s",s1);
	string s(s1);
9.程序简化：不必定义时间的结构体，可以全部转化为以 00:00:00 开始的秒
10.用 auto 遍历 map vector 等
	https://blog.csdn.net/sdnulixianrui/article/details/78627544
	注意 map 取出的是 pair 而不再是指针
	因此要用 p.first p.second
	vector 取出的直接是元素
*/
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct record
{
	string plate;
	int time;
	bool status;
};
bool cmp(record a,record b)
{
	if (a.plate!=b.plate) return a.plate<b.plate;
	else return a.time<b.time;
}
bool cmp2(record a,record b)
{
	return a.time<b.time;
}
int main()
{
	int n,k,maxtime=-1,hh,mm,ss;
	vector<record> arr;
	vector<record> vaild;
	map<string,int> my2;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++) {
		record aa;
		char s1[10],s2[4];
		scanf("%s %d:%d:%d %s",s1,&hh,&mm,&ss,s2);
		string temp(s1);
		aa.plate=s1;
		aa.time=hh*3600+mm*60+ss;
		if (strcmp(s2,"in")==0) aa.status=0;
		else if (strcmp(s2,"out")==0) aa.status=1;
		arr.push_back(aa);
	}
	sort(arr.begin(),arr.end(),cmp);
	for (int i=0;i<arr.size()-1;i++) {
		if (arr[i].plate==arr[i+1].plate&&arr[i].status==0&&arr[i+1].status==1) {
			vaild.push_back(arr[i]);
			vaild.push_back(arr[i+1]);
			int inTime=arr[i+1].time-arr[i].time;
			my2[arr[i].plate]+=inTime;
			maxtime=max(maxtime,my2[arr[i].plate]);
		}
	}
	sort(vaild.begin(),vaild.end(),cmp2);
	//注意下面统计个数的写法，是本题能否AC的关键
	int now=0,countt=0;
	for (int i=0;i<k;i++) {
		int hh,mm,ss,time2;
		scanf("%d:%d:%d",&hh,&mm,&ss);
		time2=hh*3600+mm*60+ss;
		while (now<vaild.size()&&vaild[now].time<=time2) {
			if (vaild[now].status==0) countt++;
			else countt--;
			now++;
		}
		printf("%d\n",countt);
	}
	
	for (auto &p:my2)
		if (p.second==maxtime) printf("%s ",p.first.c_str());
	printf("%02d:%02d:%02d\n",maxtime/3600,(maxtime%3600)/60,maxtime%60);
	return 0;
}
