#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    int n;
    vector<string> ans;
    cin >> n;
    cin.ignore();
    getline(cin, s, '\n');
    for (int i = 0; i < s.length();)
    {
        ans.push_back(s.substr(i, min(n, int(s.length() - i))));
        i += n;
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
            cout << ans[j][i];
        cout << endl;
    }
    return 0;
}