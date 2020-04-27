#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
typedef long long ll;
int n, arr[MAXN], L[MAXN], R[MAXN], t[MAXN];
int lowbit(int x)
{
    return x & (-x);
}

void add(int m)
{
    for (int i = m; i <= n; i += lowbit(i))
        arr[i]++;
}

int getsum(int m)
{
    int sum = 0;
    for (int i = m; i >= 0; i -= lowbit(i))
        sum += arr[i];
    return sum;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", t + i);
    for (int i = 0; i < n; i++)
    {
        L[i] = i - getsum(t[i]);
        add(t[i]);
    }
    memset(arr, 0, sizeof(arr));
    for (int i = n - 1; i >= 0; i--)
    {
        R[i] = getsum(t[i]);
        add(t[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += (ll)L[i] * (ll)R[i];
    printf("%lld\n", ans);
    return 0;
}