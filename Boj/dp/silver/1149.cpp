#include <iostream>
#define min(a,b) a<b?a:b
using namespace std;

int main() {
	int arr[1001][3];
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int dp[1001][3];
	for(int i=0;i<3;i++){
		dp[0][i] = arr[0][i];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			dp[i][j] = min(dp[i-1][(j+1)%3]+arr[i][j],
						  dp[i-1][(j+2)%3]+arr[i][j]);
		}
	}
	int mini = 987654321;
	for(int j=0;j<3;j++){
		if(mini>dp[n-1][j]) mini = dp[n-1][j];
	}
	cout << mini;
	return 0;
}