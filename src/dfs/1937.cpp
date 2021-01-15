#include <iostream>
using namespace std;
int n;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[501][501];
int dp[501][501]={0};
int dfs(int y, int x, int cnt, int before){
	if(y<0||x<0||y>=n||x>=n) return cnt-1;
	if(arr[y][x] <= before) return cnt-1;
	if(dp[y][x]!=0) return cnt+dp[y][x];
	int maxi = 0;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		int res = dfs(ny,nx,cnt+1,arr[y][x]);
		if(res>maxi) maxi = res;
	}
	dp[y][x] = maxi - cnt;
	return maxi;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);	
		}
	}
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int res = dfs(i,j,1,-1);
			if(max<res) max = res;
		}
	}
	cout << max;
	return 0;
}