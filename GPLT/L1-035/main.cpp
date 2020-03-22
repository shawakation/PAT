#include <iostream>
using namespace std;

int main()
{
    string s, s1, s2;
    int n = 0;
    while (1)
    {
        getline(cin, s, '\n');
        if (s == ".")
            break;
        n++;
        if (n == 2)
            s1 = s;
        if (n == 14)
            s2 = s;
    }
    if (s1==""&&s2=="")
        printf("Momo... No one is for you ...\n");
    else if (s1!=""&&s2=="")
        printf("%s is the only one for you...\n", s1.c_str());
    else
        printf("%s and %s are inviting you to dinner...", s1.c_str(), s2.c_str());
    return 0;
}