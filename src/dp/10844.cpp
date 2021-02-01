#include <iostream>
#define mod 1000000000;
using namespace std;
int n;
int dp[10][101]={0,};
long long int sum=0;
int main(){
	scanf("%d",&n);
	dp[0][1] = 0;
	for(int i=1;i<10;i++) dp[i][1] = 1;
	for(int j=2;j<=n;j++){
		for(int i=0;i<10;i++){
			if(i==0){ 
				dp[0][j] = dp[1][j-1]%mod;
			}
			else if(i==9){ 
				dp[9][j] = dp[8][j-1]%mod;
			}
			else dp[i][j] = (dp[i+1][j-1] + dp[i-1][j-1])%mod;	
		}	
	}
	for(int i=0;i<10;i++){
		sum += dp[i][n];
	}
	sum%=mod;
	printf("%lld",sum);
	return 0;
}