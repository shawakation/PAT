/*
1.暴力解法：要会用 stl 或者数组实现 插入排序 归并排序 用任意一个都行
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n=0;
bool flag=1;
vector<int> origin,change,temp;
int main()
{
	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int tt;
		scanf("%d",&tt);
		origin.push_back(tt);
		temp.push_back(tt);
	}
	for (int i=0; i<n; i++) {
		int tt;
		scanf("%d",&tt);
		change.push_back(tt);
	}
	for (int i=1; i<n; i++) {
		int tt=temp[i];
		int k=int(upper_bound(temp.begin(),temp.begin()+i,tt)-temp.begin());
		temp.erase(temp.begin()+i);
		temp.insert(temp.begin()+k,tt);
		if (equal(temp.begin(),temp.end(),change.begin())) {
			printf("Insertion Sort\n");
			flag=0;
			i++;
			int tt=temp[i];
			int k=int(upper_bound(temp.begin(),temp.begin()+i,tt)-temp.begin());
			temp.erase(temp.begin()+i);
			temp.insert(temp.begin()+k,tt);
			for (int h=0; h<n; h++) {
				printf("%d",temp[h]);
				if (h<n-1) printf(" ");
			}
			return 0;
		}
	}
	if (flag) {
		printf("Merge Sort\n");
		temp.assign(origin.begin(),origin.end());
		for (int step=2; step<=n; step*=2) {
			for (int i=0; i<n; i+=step)
				sort(temp.begin()+i,temp.begin()+min(i+step,n));
			if (equal(temp.begin(),temp.end(),change.begin())) {
				step*=2;
				for (int i=0; i<n; i+=step)
					sort(temp.begin()+i,temp.begin()+min(i+step,n));
				for (int h=0; h<n; h++) {
					printf("%d",temp[h]);
					if (h<n-1) printf(" ");
				}
				return 0;
			}
		}
	}
	return 0;
}
