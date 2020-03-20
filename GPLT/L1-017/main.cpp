#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char *num = new char[55];
    scanf("%s", num);
    bool isfu = 0, isou = 0;
    int startt = 0, countt = 0;
    if (num[0] == '-')
    {
        isfu = 1;
        startt++;
    }
    int len = strlen(num);
    if ((num[len - 1] - '0') % 2 == 0)
        isou = 1;
    for (int i = startt; i < len; i++)
        if (num[i] == '2')
            countt++;
    float ans = (float)countt / (len - startt);
    if (isfu)
        ans *= 1.5;
    if (isou)
        ans *= 2;
    printf("%.2f%%\n", ans * 100);
    return 0;
}