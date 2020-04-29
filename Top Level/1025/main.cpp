#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000007
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int minlen = min((int)s.length() + 1, 101);
    vector<vector<ll>> arr(minlen, vector<ll>(s.length() + 1, 1));
    for (int i = 1; i < minlen; i++)
    {
        vector<ll> num(26, 0);
        num[s[i - 1] - 'a'] = 1;
        for (int j = i + 1; j <= s.length(); j++)
        {
            arr[i][j] = (arr[i][j - 1] + arr[i - 1][j - 1] - num[s[j - 1] - 'a'] + MOD) % MOD;
            num[s[j - 1] - 'a'] = arr[i - 1][j - 1];
        }
    }
    ll ans = 0;
    for (int i = 1; i < minlen; i++)
        ans = (ans + arr[i][s.length()]) % MOD;
    printf("%lld", ans);
    return 0;
}