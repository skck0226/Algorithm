#include <iostream>

using namespace std;

int main()
{
    long long sum = 0;
    long long min = 987654321;
    long long int n;
    int a[6];
    int A[3], B[3], C[3];
    scanf("%lld", &n);
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &a[i]);
        if (min > a[i])
            min = a[i];
    }
    if (n == 1)
    {
        int max = 0;
        int sum = 0;
        for (int i = 0; i < 6; i++)
        {
            sum += a[i];
            if (max < a[i])
                max = a[i];
        }
        sum -= max;
        printf("%d\n", sum);
        return 0;
    }
    if (4 * (n - 1) * (n - 2) * min)
        sum += 4 * (n - 1) * (n - 2) * min;
    if ((n - 2) * (n - 2) * min)
        sum += (n - 2) * (n - 2) * min;
    A[0] = a[0];
    A[1] = a[5];
    A[2] = 0;
    B[0] = a[1];
    B[1] = a[4];
    B[2] = 0;
    C[0] = a[2];
    C[1] = a[3];
    C[2] = 0;
    min = 987654321;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (min > A[i] + B[j] + C[k])
                    min = A[i] + B[j] + C[k];
            }
        }
    }
    sum += 4 * min;
    min = 987654321;
    int cnt2 = 0;
    for (int i = 0; i < 3; i++)
    {
        int cnt = 0;
        if (A[i] != 0)
            cnt++;
        for (int j = 0; j < 3; j++)
        {
            if (B[j] != 0)
                cnt++;
            for (int k = 0; k < 3; k++)
            {
                if (C[k] != 0)
                    cnt++;
                if (cnt == 2)
                {
                    if (min > A[i] + B[j] + C[k])
                        min = A[i] + B[j] + C[k];
                }
                if (C[k] != 0)
                    cnt--;
            }
            if (B[j] != 0)
                cnt--;
        }
    }
    if (4 * (n - 2) * min)
        sum += (4 * (n - 2) * min);
    if (4 * (n - 1) * min)
        sum += 4 * (n - 1) * min;
    printf("%lld\n", sum);
    return 0;
}