#include <cstdio>
#include <map>
using namespace std;
struct comp
{
	bool operator()(int a,int b) const {return a>b;}
};
int main()
{
	map<int,double> arr;
	map<int,double,comp> outcome;
	int n1,n2;
	scanf("%d",&n1);
	for (int i=0;i<n1;i++) {
		int exp;
		double coe;
		scanf("%d%lf",&exp,&coe);
		arr[exp]=coe;
	}
	scanf("%d",&n2);
	for (int i=0;i<n2;i++) {
		int exp;
		double coe;
		scanf("%d%lf",&exp,&coe);
		for (map<int,double>::iterator it=arr.begin();it!=arr.end();it++) {
			int exp2=exp+(it->first);
			double coe2=coe*(it->second);
			outcome[exp2]+=coe2;
		}
	}
	for (map<int,double,comp>::iterator p=outcome.begin();p!=outcome.end();p++) {
		if (p->second==0) outcome.erase(p);
	}
	int num=outcome.size();
	if (num) {
		printf("%d ",num);
		for (map<int,double,comp>::iterator p=outcome.begin();p!=outcome.end();p++) {
			printf("%d %.1lf",p->first,p->second);
			num--;
			if (num) printf(" ");
		}
	}
	else printf("%d",num);
	return 0;
}
