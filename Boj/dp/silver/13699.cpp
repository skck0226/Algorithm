#include <iostream>

using namespace std;
long long int dp[40];	
int main(){
	int n; scanf("%d",&n);
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			dp[i] += dp[j]*dp[i-1-j];
		}
	}
	printf("%lld",dp[n]);
	return 0;
}