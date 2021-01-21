#include <iostream>
using namespace std;
int n,m;
char arr[501][10001];
int dp[501][10001]={0,};
int visited[501][10001]={0,};
int dy[3]={-1,0,1};
int dx[3]={1,1,1};
int dfs(int y, int x){
	if(y<0||y>=n) return 0;
	if(arr[y][x]=='x') return false;
	if(x==m-1) return 1;
	if(dp[y][x]!=0) return dp[y][x];
	visited[y][x] = 1;
	int ret = 0;
	for(int i=0;i<3;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
	}
	
	return ret;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
		}
	}
	int cnt = 0;
	dfs(0,0);
	
	return 0;
}