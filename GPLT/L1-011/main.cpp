#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
    string s1, s2;
    unordered_set<char> my;
    getline(cin, s1, '\n');
    getline(cin, s2, '\n');
    for (char &s : s2)
        my.insert(s);
    for (int i = 0; i < s1.length();)
        if (my.find(s1[i]) != my.end())
            s1.erase(i, 1);
        else
            i++;
    printf("%s\n", s1.c_str());
    return 0;
}