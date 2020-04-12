#include <iostream>
using namespace std;
int main()
{
    int k, sumt = 0, maxnum = -1, left = 0, right = 0, left_t = 0, right_t = 0;
    scanf("%d", &k);
    int *arr = new int[k];
    for (int i = 0; i < k; i++)
    {
        scanf("%d", arr + i);
        sumt += arr[i];
        right_t = i;
        if (sumt > maxnum)
        {
            maxnum = sumt;
            left = left_t;
            right = right_t;
        }
        else if (sumt < 0)
        {
            sumt = 0;
            left_t = i + 1;
            right_t = i + 1;
        }
    }
    if (maxnum < 0)
        printf("%d %d %d\n", 0, arr[0], arr[k - 1]);
    else
        printf("%d %d %d\n", maxnum, arr[left], arr[right]);
    return 0;
}