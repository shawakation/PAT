#include <bits/stdc++.h>
using namespace std;
unordered_map<unsigned, unordered_set<unsigned>> my;
struct my_comp
{
    bool operator()(const unsigned &a, const unsigned &b) const
    {
        if (my[a].find(b) == my[a].end())
            return 0;
        else
            return 1;
    }
};
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        unsigned k1, k2;
        scanf("%u %u", &k1, &k2);
        my[k1].insert(k2);
        my[k2].insert(k1);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        scanf("%d", &k);
        set<unsigned, my_comp> myt;
        for (int j = 0; j < k; j++)
        {
            unsigned t;
            scanf("%u", &t);
            myt.insert(t);
        }
        if (myt.size() == k)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}