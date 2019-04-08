#include <iostream>
#include <set>
#include <string>
using namespace std;
int main()
{
	long n;
	set<int> my;
	scanf("%ld",&n);
	for (long i=0;i<n;i++) {
		string s;
		int sum=0;
		cin>>s;
		for (int j=0;j<s.length();j++) sum+=s[j]-'0';
		my.insert(sum);
	}
	int countt=my.size();
	printf("%d\n",countt);
	for (auto p:my) {
		printf("%d",p);
		countt--;
		if (countt>0) printf(" ");
	}
	return 0;
}
