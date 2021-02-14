#include <iostream>
#define INF 1000000009
using namespace std;
long long int dp[100001];
int main(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;
	
	for(int i=7;i<=100000;i++){
		dp[i] = dp[i-2]%INF + dp[i-4]%INF + dp[i-6]%INF;
		dp[i] %= INF;
	}
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n; scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	return 0;
}