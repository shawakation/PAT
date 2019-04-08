/*
1.string数组的用法：string[a][b];
        每个元素是一个string
*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
	unsigned short n,k,t;
	string stu[1001][2],zhunkao,kaoshi; 
	cin>>n;
	for (unsigned short i=1;i<=n;i++) {
		cin>>zhunkao>>t>>kaoshi;
		stu[t][0]=zhunkao;
		stu[t][1]=kaoshi;
	}
	cin>>k;
	for (unsigned short i=1;i<=k;i++) {
		cin>>t;
		cout<<stu[t][0]<<' '<<stu[t][1]<<endl;
	}
	return 0;
}
