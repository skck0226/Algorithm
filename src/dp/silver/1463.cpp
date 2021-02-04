#include <iostream>
using namespace std;
#define max(a,b) a<b?a:b
int main() {
	int n;
	cin >> n;
	int dp[1000001];
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	for(int i=4;i<=n;i++){
		
		dp[i]=dp[i-1]+1;
		
		if(i%3==0){
			dp[i]=max(dp[i/3]+1,dp[i]);
		}	
		if(i%2==0){
			dp[i]=max(dp[i/2]+1,dp[i]);
		}
		
	}
	cout << dp[n]<<endl;
	return 0;
}