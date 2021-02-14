#include <iostream>
#define max(a,b) a>b?a:b
using namespace std;
int n; 
int dp[21]={0,};
int day[16];
int pay[16];
int main(){
	int max = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&day[i],&pay[i]);
	}
	for(int i=n;i>0;i--){
		if(i+day[i]>n+1) dp[i] = dp[i+1];
		else{
			dp[i] = max(dp[i+1],dp[i+day[i]]+pay[i]);
		}
	}
	cout << dp[1];
	return 0;
}
//dp에서 명심해야할 것; 너가 뭔갈 짜려고 하지마라 브루트포스 아니다 그냥 최적 부분구조를 찾아라.