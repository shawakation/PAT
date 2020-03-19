#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int strtoint(string s)
{
    stringstream ss(s);
    int a;
    ss >> a;
    return a;
}
int main()
{
    string a, b, tt;
    bool isa = 1, isb = 1;
    ios::sync_with_stdio(false);
    getline(cin, tt, '\n');
    if (tt[0] == ' ')
    {
        stringstream ss(tt);
        ss >> b;
        for (char &t : b)
            if (!isdigit(t))
            {
                isb = 0;
                break;
            }
        if (isb)
        {
            int numb = strtoint(b);
            if (!(1 <= numb && numb <= 1000))
                printf("? + %d = ?\n", numb);
            else
                printf("? + ? = ?\n");
        }
        return 0;
    }
    stringstream ss(tt);
    ss >> a >> b;
    if (isa)
        for (char &t : a)
            if (!isdigit(t))
            {
                isa = 0;
                break;
            }
    for (char &t : b)
        if (!isdigit(t))
        {
            isb = 0;
            break;
        }
    int numa = strtoint(a), numb = strtoint(b);
    if (isa)
        if (!(1 <= numa && numa <= 1000))
            isa = 0;
    if (isb)
        if (!(1 <= numb && numb <= 1000))
            isb = 0;
    if (isa)
        printf("%d", numa);
    else
        printf("?");
    printf(" + ");
    if (isb)
        printf("%d", numb);
    else
        printf("?");
    printf(" = ");
    if (isa && isb)
        printf("%d\n", numa + numb);
    else
        printf("?\n");
    return 0;
}