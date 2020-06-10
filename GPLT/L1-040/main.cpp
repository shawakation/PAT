#include <iostream>
using namespace std;

int main()
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        char sex;
        float high;
        scanf("%c %f\n", &sex, &high);
        if (sex == 'M')
            printf("%.2f\n", high / 1.09);
        else if (sex == 'F')
            printf("%.2f\n", high * 1.09);
    }
    return 0;
}