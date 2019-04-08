/*
1.一次AC！注意把思维判断过程具体化
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for (int i=0; i<k; i++) {
		stack<int> ss;
		int curnum=0;
		bool flag=1;
		vector<int> arr(n);
		for (int j=0; j<n; j++) scanf("%d",&arr[j]);
		for (int j=0; j<n; j++) {
			if (arr[j]>curnum) {
				for (int kk=curnum+1; kk<=arr[j]; kk++) ss.push(kk);
				curnum=arr[j];
				if (ss.size()>m) {
					printf("NO\n");
					flag=0;
					break;
				}
				ss.pop();
			} else {
				if (ss.top()==arr[j]) ss.pop();
				else {
					printf("NO\n");
					flag=0;
					break;
				}
			}
		}
		if (flag) printf("YES\n");
	}
	return 0;
}
