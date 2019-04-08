/*
重打一遍
首先想到排序的思想
*/
#include <iostream>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {
    return a > b;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n+1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    sort(a+1, a+n+1, comp);
    int ans = 0, p = 1;
    while(ans <= n && a[p] > p) {
        ans++;
        p++;
    }
    cout<<ans;
    return 0;
}
