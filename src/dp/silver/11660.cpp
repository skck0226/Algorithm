#include <iostream>

using namespace std;
int n,m;
int dp[1025][1025]={0,};
int to(int y1, int x1, int y2, int x2){
	return dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1];
}
int sum(int y, int x){
	return dp[y-1][x] + dp[y][x-1] + dp[y][x] - dp[y-1][x-1];
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&dp[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j] = sum(i,j);
		}
	}
	// cout << endl;
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=n;j++){
	// 		printf("%5d",dp[i][j]);
	// 	}
	// 	cout << endl;
	// }
	for(int i=0;i<m;i++){
		int y1,x1,y2,x2; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int num = to(x1,y1,x2,y2);
		printf("%d\n",num);
	}
		
	return 0;
}