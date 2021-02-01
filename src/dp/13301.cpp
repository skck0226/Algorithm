#include <iostream>
using namespace std;

int main() {
	int n; scanf("%d",&n);
	long long int dp[88];
	long long int sum = 0;
	dp[0] = 1; dp[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	sum += dp[n]*2 + dp[n-1]*2;
	printf("%lld",sum);
	return 0;
}