#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
unordered_map<string,int> ump;
int main()
{
	int n,p;
	char s[20];
	scanf("%d%d",&n,&p);
	int a[p],vis[p];
	mem(a,-1);
	mem(vis,-1);
	ump.clear();
	int len,idx,sum,f=1;
	for (int i=0; i<n; i++) {
		scanf("%s",s);
		len=strlen(s);
		if (ump[s]!=0) {
			printf(" %d",a[ump[s]==-1?0:ump[s]]);
			continue;
		}
		if (len==1) sum=s[len-1]-'A';
		else if(len==2) sum=s[len-1]-'A' + (s[len-2]-'A')*32;
		else sum=s[len-1]-'A' + (s[len-2]-'A')*32 + (s[len-3]-'A')*32*32;
		for (int j=0;; j++) {
			idx=(sum+j*j)%p;
			if (vis[idx]==-1) {
				a[i]=idx;
				vis[idx]=1;
				ump[s]=i==0?-1:i;
				break;
			}
			idx=(sum-j*j+j*j*p)%p;
			if (vis[idx]==-1) {
				a[i]=idx;
				vis[idx]=1;
				ump[s]=i==0?-1:i;
				break;
			}
		}
		if (f) {
			f=0;
			printf("%d",a[i]);
		} else printf(" %d",a[i]);
	}
	printf("\n");
	return 0;
}
