#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num;
    int countt = 0;
    while (cin >> num)
    {
        countt++;
        if (num == "250")
        {
            printf("%d\n", countt);
            break;
        }
    }
    return 0;
}