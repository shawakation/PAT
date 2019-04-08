/*
1.用数组来做标记的思想
2.vector定义的方法：vector<int> a(n)表示初始化n个元素的a
					vector<int> a[n]表示n个元素的数组vector<int> a
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	short k,flag=0;
	short *istrue=new short[10000];
	memset(istrue,0,sizeof(istrue));
	cin>>k;
	vector<int> arr(k);
	for (short i=0;i<k;i++) {
		short num;
		cin>>num;
		arr[i]=num;
		while (num!=1) {
			if (num%2!=0) num=num*3+1;
			num/=2;
			if (istrue[num]==1) break;
			istrue[num]=1;
		}
	}
	sort(arr.begin(),arr.end(),cmp);
	for (short i=0;i<arr.size();i++) {
		if (istrue[arr[i]]==0) {
			if (flag==1) cout<<' ';
			cout<<arr[i];
			flag=1;
		}
	}
	return 0;
}
