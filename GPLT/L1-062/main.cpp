#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        char num[7] = {'\0'};
        scanf("%s\n", num);
        if (num[0] - '0' + num[1] - '0' + num[2] - '0' == num[3] - '0' + num[4] - '0' + num[5] - '0')
            printf("You are lucky!\n");
        else
            printf("Wish you good luck.\n");
    }
    return 0;
}