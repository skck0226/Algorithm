#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K, N;
int maxi = 0;
vector<int> arr;
int check(long long len)
{
    int res = 0;
    for (int i = 0; i < K; i++)
    {
        res += arr[i] / len;
    }
    if (res >= N)
    {
        printf("%lld %d %d\n", len, res, maxi);
        if (maxi < len)
            maxi = len;
        if (!maxi)
            return 1;
        return maxi;
    }
    else
    {
        printf("%lld %d %d\n", len, res, maxi);
        return 0;
    }
}
int main()
{
    int a;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    long long start = 1;
    long long end = arr.back();
    while (start + 1 < end)
    {
        long long mid = (start + end) / 2;
        if (check(end)) 
            start = mid;
        else
            end = mid;
    }
    printf("%d\n", maxi);
    return 0;
}