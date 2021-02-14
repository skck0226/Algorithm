#include <iostream>
#include <string.h>
#define INF 987654321
#define min(a,b) a<b?a:b
using namespace std;
int n;
int dp[100001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		dp[i] = INF;
	}
	dp[2] = 1; dp[4] = 2; dp[5] = 1;
	for(int i=6;i<=n;i++){
		if(dp[i-5]!=INF){
			dp[i] = dp[i-5] + 1;
		}
		if(dp[i-2]!=INF){
			dp[i] = min(dp[i],dp[i-2]+1);
		}
	}
	if(dp[n]==INF) cout << -1;
	else cout << dp[n];
	return 0;
}