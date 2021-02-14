#include <iostream>
#include <vector>
#include <cmath>
#define INF 987654321
using namespace std;
vector<int> v;
int dp[50005];
int main(){
	int n; scanf("%d",&n);
	for(int i=0;i<=n;i++) dp[i] = INF;
	dp[0] = 0;
	v.push_back(0);
	for(int i=1;i<=sqrt(n);i++){
		dp[i*i] = 1;
		v.push_back(i*i);
	}
	for(int i=2;i<=n;i++){
		int min = INF;
		for(int j=0;;j++){
			if(v[j]>i) break;
			if(min>dp[i-v[j]]+1) min = dp[i-v[j]]+1;
		}
		dp[i] = min;
	}
	
	cout << endl << dp[n];
	return 0;
}