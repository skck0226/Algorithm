#include <iostream>
#define INF 1000000009
using namespace std;
long long int dp[2][100001];
int main(){
	dp[0][1] = 0;
	dp[1][1] = 1;
	dp[0][2] = 1;
	dp[1][2] = 1;
	dp[0][3] = 2;
	dp[1][3] = 2;
	for(int i=4;i<=100000;i++){
		dp[0][i] = dp[1][i-1]%INF + dp[1][i-2]%INF
		+ dp[1][i-3]%INF;
		dp[1][i] = dp[0][i-1]%INF + dp[0][i-2]%INF 
		+ dp[0][i-3]%INF;
		dp[0][i] %= INF;
		dp[1][i] %= INF;	
	}
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n; scanf("%d",&n);
		printf("%lld %lld\n",dp[1][n],dp[0][n]);
	}
	return 0;
}