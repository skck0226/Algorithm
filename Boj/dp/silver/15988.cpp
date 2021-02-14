#include <iostream>
#define INF 1000000009
using namespace std;
long long int dp[1000001];
int main(){
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for(int i=4;i<=1000000;i++){
		dp[i] = dp[i-1]%INF + dp[i-2]%INF + dp[i-3]%INF;
		dp[i] %= INF;
	}
	int t; scanf("%d",&t);
	for(int z=0;z<t;z++){
		int n; scanf("%d",&n);
		printf("%lld\n",dp[n]);
	}
	
	return 0;
}