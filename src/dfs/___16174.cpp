#include <iostream>
using namespace std;
int n;
int arr[65][65];
int dy[2] = {1,0};
int dx[2] = {0,1};
int flag = 0;
bool dfs(int y, int x){	
	bool res = false;
	if(y==n-1&&x==n-1){
		// flag = 1;
		return true;
	}
	for(int i=0;i<2&&!res;i++){
		int ny = y + arr[y][x]*dy[i];
		int nx = x + arr[y][x]*dx[i];
		if(ny<0||nx<0||ny>=n||nx>=n) continue;
		res|=dfs(ny,nx);
		// if(flag==1) return true;
	}
	// return false;
	return true;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	if(dfs(0,0)) cout << "HaruHaru";
	else cout << "Hing";
	return 0;
}