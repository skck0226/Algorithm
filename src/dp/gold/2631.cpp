#include <iostream>

using namespace std;
int n;
int dp[2][202];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&dp[0][i]);
		dp[1][i] = 1;
	}
	int max;
	for(int i=1;i<n;i++){
		max = 0;
		for(int j=0;j<i;j++){
			if(dp[0][j] < dp[0][i]){
				if(max<dp[1][j]) max = dp[1][j];
			}
		}
		dp[1][i] += max;
	}
	max = 0;
	for(int i=0;i<n;i++){
		if(max<dp[1][i]) max = dp[1][i];
	}
	cout << n-max;
	return 0;
}