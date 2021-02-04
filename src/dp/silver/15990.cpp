#include <iostream>
#define INF 1000000009
using namespace std;
long long int dp[4][100001];
int main(){
	int t; scanf("%d",&t);
	dp[1][1] = dp[0][1] = 1;
	dp[2][2] = dp[0][2] = 1;
	dp[1][3] = 1;
	dp[2][3] = 1;	
	dp[3][3] = 1;
	dp[0][3] = 3; 
	for(int i=4;i<=100000;i++){
		dp[1][i] = dp[2][i-1]%INF + dp[3][i-1]%INF;
		dp[2][i] = dp[1][i-2]%INF + dp[3][i-2]%INF;
		dp[3][i] = dp[1][i-3]%INF + dp[2][i-3]%INF;
		dp[1][i] %= INF;
		dp[2][i] %= INF;
		dp[3][i] %= INF;
		dp[0][i] = dp[1][i] + dp[2][i] + dp[3][i]; 
		dp[0][i] %= INF;
	}
	// for(int i=1;i<=100;i++){
	// 	cout << dp[0][i] << endl;
	// }
	for(int z=0;z<t;z++){
		int n; scanf("%d",&n);
		printf("%lld\n",dp[0][n]);
	}
	return 0;
}