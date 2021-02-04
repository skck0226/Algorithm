#include <iostream>
using namespace std;
int n;
int dp[2][1000001];
int main(){
	scanf("%d",&n);
	dp[0][0] = dp[1][0] = 987654321;
	dp[0][1] = 0;
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		dp[0][i] = dp[0][i-1] + 1;
		dp[1][i] = i-1;
		if(i%3==0){
			if(dp[0][i/3]+1 < dp[0][i]){
				dp[0][i] = dp[0][i/3]+1;
				dp[1][i] = i/3;
			}
		}
		if(i%2==0){
			if(dp[0][i/2]+1 < dp[0][i]){
				dp[0][i] = dp[0][i/2]+1;
				dp[1][i] = i/2;
			}
		}	
	}
	cout << dp[0][n] << endl;
	int x=n;
	while(1){
		cout << x << " ";
		if(x==1) break;
		x = dp[1][x];
	}
	return 0;
}