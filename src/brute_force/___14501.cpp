#include <iostream>

using namespace std;

int main(){
	int n; 
	int dp[16]={0,};
	int arr[16][2];
	int max = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	for(int i=n;i>0;i--){
		int next = i+arr[i][0];
		if(next>(n+1)){ 
			max = 0;
			for(int j=i;j<=n;j++){
				if(max<dp[j]) max = dp[j];
			}
			dp[i] = max;
			continue;
		}
		int max = 0;
		for(int j=i;j<next;j++){
			if(max<dp[j]) max = dp[j];
		}
		if(max<(arr[i][1]+dp[next])) max = (arr[i][1]+dp[next]);
		dp[i] = max;	
	}
	max = 0;
	for(int i=1;i<=n;i++){
		if(max<dp[i]) max = dp[i];	
	}
	cout << max;
	return 0;
}