#include <iostream>

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int arr[100001];
	int dp[100001];
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	dp[1]=arr[1];
	for(int i=2;i<=n;i++){
		if(0<dp[i-1]) dp[i] = dp[i-1]+arr[i];
		else dp[i] = arr[i];
	}
	int max = dp[1];
	for(int i=1;i<=n;i++){
		if(max<dp[i]) max = dp[i];
	}
	cout << max;
	return 0;
}