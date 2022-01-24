#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    vector<int> pack;
    vector<int> one;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > 6 * b)
        {
            pack.push_back(6 * b);
        }
        else
            pack.push_back(a);
        one.push_back(b);
    }
    sort(pack.begin(), pack.end());
    sort(one.begin(), one.end());
    if (pack[0] > one[0] * (n % 6))
        printf("%d\n", pack[0] * (n / 6) + one[0] * (n % 6));
    else
        printf("%d\n", pack[0] * (n / 6 + 1));
    return 0;
}