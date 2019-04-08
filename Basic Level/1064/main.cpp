/*
1.set有自动查重和自动排序的功能，当数组中有不允许重复的数时可以用
        或者需要排序时(有重复的用multiset)
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	int N;
	set<short> shuzu;
	cin>>N;
	for (int i=0;i<N;i++) {
		string str;
		cin>>str;
		short sum=0;
		for (int i=0;i<str.length();i++)
			sum+=str[i]-'0';
		shuzu.insert(sum);
	}
	cout<<shuzu.size()<<endl;
	int j=0;
	for (set<short>::iterator i=shuzu.begin();i!=shuzu.end();i++,j++) {
		cout<<*i;
		if (j!=shuzu.size()-1) cout<<' ';
	}
	return 0;
}
