#include <iostream>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int n,m,k;
int arr[102][102];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int dfs(int y,int x){
	if(y<1||x<1||y>n||x>m) return 0;	
	if(arr[y][x]==0) return 0;
	arr[y][x] = 0;
	int ret = 1;
	for(int i=0;i<4;i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		ret += dfs(ny,nx);
		
	}
	return ret;
}
int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<k;i++){
		int a,b; scanf("%d %d",&a,&b);
		arr[a][b] = 1;
	}
	int maxi = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j]==1){
				int res = dfs(i,j);
				if(maxi<res) maxi = res;
			}
		}
	}
	cout << maxi;
	return 0;
}