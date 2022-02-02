#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int square = 1;
    vector<int> square_vector;
    vector<int> v;
    while (square <= n)
    {
        square_vector.push_back(square);
        square *= 2;
    }
    while (square_vector.size())
    {
        int back = square_vector.back();
        if (n < back)
        {
            square_vector.pop_back();
            continue;
        }
        n -= back;
        v.push_back(back);
        square_vector.pop_back();
    }
    if (v.size() <= m)
        printf("0\n");
    else
    {

        int sum = 0;
        for (int i = m; i < v.size(); i++)
        {
            sum += v[i];
        }
        printf("%d\n", v[m - 1] - sum);
    }
    return 0;
}