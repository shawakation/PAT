#include <map>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,sum=0;
	map<int,string> my;
	cin>>n;
	for (int i=0;i<n;i++) {
		string name;
		int num;
		cin>>name>>num;
		my[num]=name;
		sum+=num;
	}
	sum/=n*2;
	cout<<sum<<' ';
	map<int,string>::iterator it=my.begin();
	for (;it!=my.end()&&it->first<sum;it++) ;
	if (sum-(it->first)>((++it)->first)-sum) cout<<it->second;
	else cout<<(--it)->second;
	return 0;
}
