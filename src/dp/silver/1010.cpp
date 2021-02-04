#include <iostream>
using namespace std;
int dp[31][31]={0,};
int pascal(int n, int r){
	if(n==r) return 1;
	if(r==1) return n;
	if(dp[n][r]!=0) return dp[n][r];
	return dp[n][r] = pascal(n-1,r-1) + pascal(n-1,r);
}

int main() {
	int t; scanf("%d",&t);
	for(int i=0;i<t;i++){
		int a,b; scanf("%d %d",&a,&b);
		cout << pascal(b,a)<<endl;
	}
	return 0;
}