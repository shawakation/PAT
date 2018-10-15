/*
尽量不要自己写排序、查找算法，用已有的：
			algorithm: sort  (vector deque arr)
			map string set: find
*/
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n,m;
	map<int,int> couples;
	vector<int> persons;
	cin>>n;
	for (int i=0;i<n;i++) {
		int wife,husband;
		cin>>wife>>husband;
		couples[wife]=husband;
	}
	cin>>m;
	for (int i=0;i<m;i++) {
		int man;
		cin>>man;
		persons.push_back(man);
	}
	for (int i=0;i<persons.size();i++) {
		map<int,int>::iterator it=couples.find(persons[i]);
		if (it!=couples.end()) {
			int hus=it->second;
			vector<int>::iterator it2=find(persons.begin(),persons.end(),hus);
			if (it2!=persons.end()) {
				persons.erase(persons.begin()+i);
				persons.erase(it2);
				i--;
			}
		}
	}
	sort(persons.begin(),persons.end());
	cout<<persons.size()<<endl;
	for (int i=0;i<persons.size();i++) {
		printf("%05d",persons[i]);
		if (i!=persons.size()-1) cout<<' ';
	}
	return 0;
}
