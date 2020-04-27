#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct person
{
    char name[10];
    int age, worth;
    person(char *_name, int _age, int _worth) : age(_age), worth(_worth)
    {
        strcpy(name, _name);
    }
    bool operator<(const person &a) const
    {
        if (a.worth != worth)
            return worth > a.worth;
        else if (a.age != age)
            return age < a.age;
        else
            return strcmp(name, a.name) < 0;
    }
};
int main()
{
    int n, k;
    vector<person> arr;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        char name[10];
        int age, worth;
        scanf("%s %d %d\n", name, &age, &worth);
        arr.push_back(person(name, age, worth));
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; i++)
    {
        int m, Amin, Amax;
        scanf("%d %d %d", &m, &Amin, &Amax);
        int mt = m;
        printf("Case #%d:\n", i + 1);
        for (auto &p : arr)
        {
            if (mt == 0)
                break;
            if (p.age >= Amin && p.age <= Amax)
            {
                printf("%s %d %d\n", p.name, p.age, p.worth);
                mt--;
            }
        }
        if (mt == m)
            printf("None\n");
    }
    return 0;
}