#include <iostream>
#define mod 10007
using namespace std;
int n;
int dp[10][1001]={0,};
int sum[1001]={0,};
int main(){
	scanf("%d",&n);
	for(int i=0;i<10;i++){
		dp[i][1] = 1;
	}
	sum[1] = 10;
	for(int j=2;j<=n;j++){
		for(int i=0;i<10;i++){
			for(int k=0;k<=i;k++){
				dp[i][j] +=	dp[k][j-1]%mod;
			}
			sum[j] += dp[i][j];
			sum[j]%=mod;
		}
	}
	// for(int i=1;i<10;i++){
	// 	for(int j=1;j<=n;j++){
	// 		printf("%5d",dp[i][j]);
	// 	}
	// 	cout << endl;
	// }
	cout << sum[n];
	return 0;
}