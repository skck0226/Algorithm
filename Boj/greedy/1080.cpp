#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main()
{
    int arr_from[51][51], arr_to[51][51];
    int cnt = 0;
    int min = 0;
    int diff_cnt = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &arr_from[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &arr_to[i][j]);
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if (arr_from[i][j] != arr_to[i][j])
            {
                // printf("change %d %d \n", i, j);
                for (int k = 0; k < 3; k++)
                {
                    for (int l = 0; l < 3; l++)
                    {
                        arr_from[i + k][j + l] = (arr_from[i + k][j + l] + 1) % 2;
                    }
                }
                // for (int k = 0; k < 3; k++)
                // {
                //     for (int l = 0; l < 3; l++)
                //     {
                //         printf("%d", arr_from[i + k][j + l]);
                //     }
                //     printf("\n");
                // }
                cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr_from[i][j] != arr_to[i][j])
                diff_cnt++;
        }
    }
    if (diff_cnt != 0)
        printf("-1\n");
    else
        printf("%d\n", cnt);
    return 0;
}