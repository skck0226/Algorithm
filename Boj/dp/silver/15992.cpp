#include <iostream>
#include <string.h>
#define INF 1000000009
using namespace std;
long long int dp[1001][1001];
int main(){
	for(int i=0;i<=1000;i++)
		memset(dp[i],0,sizeof(long long int*)*1001);
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;	
	dp[3][1] = 1;
	dp[3][2] = 2;
	dp[3][3] = 1;	
	for(int i=4;i<=1000;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = dp[i-1][j-1]%INF + dp[i-2][j-1]%INF + dp[i-3][j-1]%INF;
			dp[i][j] %= INF;
		}
	}
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n,m; scanf("%d %d",&n,&m);
		printf("%lld\n",dp[n][m]);
	}
	return 0;
}