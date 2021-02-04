#include <iostream>
#include <string.h>
#define max(a,b) a>b?0:1
using namespace std;
int n;
int dp[2][303];
int arr[303];
int cnt[2][303];
int main(){
	for(int i=0;i<2;i++) memset(cnt[i],0,sizeof(int*)*303);
	for(int i=0;i<2;i++) memset(dp[i],0,sizeof(int*)*303);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	dp[0][0] = arr[0];
	dp[1][0] = 0;
	cnt[0][0] = 1;
	for(int i=1;i<n-1;i++){	
		int big = max(dp[0][i-1],dp[1][i-1]);
		dp[1][i] = dp[big][i-1];
		if(cnt[0][i-1]==2){
			dp[0][i] = dp[1][i-1] + arr[i];
			cnt[0][i] = 1;
			continue;
		}
		dp[0][i] = dp[big][i-1] + arr[i];
		cnt[0][i] = cnt[big][i-1] + 1;	
	}
	if(cnt[0][n-2]==2) dp[0][n-1] = dp[1][n-2] + arr[n-1];
	else dp[0][n-1] = dp[0][n-2] + arr[n-1];
	// for(int i=0;i<2;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// for(int i=0;i<2;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout << cnt[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[0][n-1];
	return 0;
}