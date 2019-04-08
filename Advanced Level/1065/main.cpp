#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		long long a,b,c,res;
		scanf("%lld %lld %lld",&a,&b,&c);
		res=a+b;
		if (a>0&&b>0&&res<0) printf("Case #%d: true\n",i+1);
		else if (a<0&&b<0&&res>=0) printf("Case #%d: false\n",i+1);
		else {
			if (res>c) printf("Case #%d: true\n",i+1);
			else printf("Case #%d: false\n",i+1);
		}
	}
	return 0;
}
