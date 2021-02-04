#include <iostream>

using namespace std;

int main(){
	int n; scanf("%d",&n);
	long long int dp0[100],dp1[100];
	dp1[1] = 1;
	dp0[1] = 0;
	for(int i=2;i<=n;i++){
		dp1[i] = dp0[i-1];
		dp0[i] = dp0[i-1] + dp1[i-1];
	}
	printf("%lld",dp1[n]+dp0[n]);
	return 0;
}