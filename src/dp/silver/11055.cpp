#include <iostream>

using namespace std;
int n;
int dp[2][1001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&dp[0][i]);
		dp[1][i] = dp[0][i];
	}
	for(int i=1;i<n;i++){
		int max = 0;
		for(int j=0;j<i;j++){
			if(dp[0][j]<dp[0][i]){
				if(max<dp[1][j]) max = dp[1][j];
			}
		}
		dp[1][i] += max;
	}
	int max = 0;
	for(int i=0;i<n;i++){
		if(max<dp[1][i]) max = dp[1][i];
	}
	cout << max;
	return 0;
}