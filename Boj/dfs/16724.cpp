#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int n,m;
char arr[1001][1001];
int isCycle[1001][1001];
int visited[1001][1001];
int cnt = 0;
int dfs(int y, int x){
	if(isCycle[y][x]==1) return 1;
	if(visited[y][x]==1){
		cnt++;
		isCycle[y][x] = 1;
		return 1;
	}
	visited[y][x] = 1;
	char dir = arr[y][x];
	int ny=y,nx=x;
	if(dir=='U') ny--;
	if(dir=='D') ny++;
	if(dir=='R') nx++;
	if(dir=='L') nx--;
	int res = dfs(ny,nx);
	if(res == 1) isCycle[y][x] = 1;
	return res;
}
int main() {
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		char c; scanf("%c",&c);
		for(int j=0;j<m;j++){
			scanf("%c",&arr[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){		
			if(isCycle[i][j]==1) continue;
			dfs(i,j);
		}
	}
	cout << cnt;
	return 0;
}