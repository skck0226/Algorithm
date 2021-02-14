#include <iostream>
#define max(a,b) a<b?a:b
using namespace std;
int n;
int arr[1001][1001];
int dp[3][1001];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int maxi2=987654321;
	for(int i=0;i<3;i++){
		dp[0][0] = arr[i][0];
		for(int j=1;j<n-1;j++){
			dp[1][j] = dp[0][j-1]+arr[1][j];
			dp[2][j] = dp[0][j-1]+arr[2][j];
		}
		int maxi1=987654321;
		for(int j=0;j<3;j++){
			if(i==j) dp[j][n-1] = 987654321;
			dp[j][n-1] = max(dp[(j+1)%3][n-2]+arr[j][n-1],
							 dp[(j+2)%3][n-2]+arr[j][n-1]);
			if(maxi1>dp[j][n-1]) maxi1 = dp[j][n-1];
		}	
		if(maxi2>maxi1) maxi2 = maxi1;
	}
	cout << maxi2;
	return 0;
}