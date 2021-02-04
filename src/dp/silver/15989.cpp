#include <iostream>
using namespace std;

int main() {
	int t; scanf("%d",&t);
	int dp[10001];
	int dp_tri[10001];
	dp[1]=1; dp[2]=2; dp[3]=3; dp_tri[3]=1;
	for(int i=4;i<=10000;i++){
		dp[i] = 1 + dp[i-2] + dp[i-3] - dp_tri[i-2];
		dp_tri[i] = dp[i-3];
	}
	for(int z=0;z<t;z++){
		int n; scanf("%d",&n);	
		cout << dp[n]<<endl;
	}
	
	return 0;
}