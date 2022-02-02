#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, a;
    vector<int> A, B;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        A.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        B.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i] * B[i];
    }
    printf("%d\n", sum);
    return 0;
}