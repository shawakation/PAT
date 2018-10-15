#include <cstdio>
#include <memory.h>
using namespace std;
int main()
{
	unsigned short n;
	unsigned int max=0,maxscore=0;
	unsigned int grade[1001];
	memset(grade,0,sizeof(grade));
	scanf("%d",&n);
	for (unsigned short i=1;i<=n;i++) {
		unsigned short a,b,c;
		scanf("%d-%d %d",&a,&b,&c);
		grade[a]+=c;
		if (grade[a]>maxscore) {
			maxscore=grade[a];
			max=a;
		}
	}
	printf("%d %d",max,maxscore);
	return 0;
}
