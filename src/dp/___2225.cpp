#include <iostream>
#define INF 1000000000
using namespace std;
int n,k;
int dp[202][202];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		dp[1][i] = 1;
	}
	for(int i=1;i<=k;i++){
		dp[i][1] = i;
	}
	for(int i=2;i<=k;i++){
		for(int j=2;j<=n;j++){
			dp[i][j] = dp[i-1][j]%INF + dp[i][j-1]%INF;
		}
	}
	// cout << dp[k][n];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			printf("%5d",dp[i][j]);
		}
		cout << endl;
	}
	return 0;
}