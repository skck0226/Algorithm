#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    vector<int> crane, box;
    scanf("%d", &n);
    int crane_max = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (crane_max < a)
            crane_max = a;
        crane.push_back(a);
    }
    scanf("%d", &m);
    sort(crane.begin(), crane.end(), greater<int>());
    int box_max = 0;
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        if (box_max < a)
            box_max = a;
        box.push_back(a);
    }
    sort(box.begin(), box.end(), greater<int>());
    if (crane_max < box_max)
    {
        printf("-1\n");
        return 0;
    }
    int cnt = 0;
    while (box.size())
    {
        cnt++;
        for (int i = crane.size() - 1; i >= 0; i--)
        {
            if (!box.size())
                break;
            for (int j = 0; j < box.size(); j++)
            {
                if (box[j] <= crane[i])
                {
                    box.erase(box.begin() + j);
                    break;
                }
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}