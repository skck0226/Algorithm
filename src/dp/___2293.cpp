#include <iostream>
#define min(a,b) a<b?a:b
#define INF 987654321
using namespace std;
int n,k;
int value[101];
int dp[2][10001];
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		dp[0][i] = INF;
		dp[1][i] = 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&value[i]);
		dp[0][value[i]] = 1;
		dp[1][value[i]] = 1;
	}
	for(int i=2;i<=k;i++){
		for(int j=0;j<n;j++){
			if(dp[0][i-value[j]]!=INF){
				dp[1][i] += dp[1][i-value[j]];
				dp[0][i] = dp[0][i-value[j]];
			}
		}
	}
	for(int i=1;i<=k;i++){
		cout << dp[1][i] << endl;
	}
	return 0;
}