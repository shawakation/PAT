/*
1.c++类的定义
    函数别忘加  public:
*/
#include <iostream>
using namespace std;
class Number
{
	public:
		long long a;
		long long b;
		long long c;
	public:
		void judge()
		{
			if (a+b>c) cout<<"true\n";
			else cout<<"false\n";
		}
		void input()
		{
			cin>>this->a>>this->b>>this->c;
		}
};
int main()
{
	unsigned short n;
	cin>>n;
	Number *num=new Number[n];
	for (unsigned short i=0;i<n;i++) num[i].input();
	for (unsigned short i=0;i<n;i++) {
		cout<<"Case #"<<i+1<<": ";
		num[i].judge();
	}
	return 0;
}
