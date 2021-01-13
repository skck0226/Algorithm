#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n;
int mini=987654321, maxi=0;
int arr[101][101];
int visited[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int check(int vy, int vx, int height){
	if(vy<0||vx<0||vy>=n||vx>=n) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]<=height) return false;
	return true;
}
void bfs(int y, int x , int height){
	queue<int> qy,qx;
	qy.push(y); qx.push(x);
	visited[y][x] = 1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx,height)){
				visited[ny][nx]=1;
				qy.push(ny); qx.push(nx);
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			if(mini>arr[i][j]) mini = arr[i][j];
			if(maxi<arr[i][j]) maxi = arr[i][j];
		}
	}
	int maxsafe=0;
	for(int h=mini; h<maxi; h++){
		for(int i=0;i<101;i++){
			memset(visited[i],0,sizeof(int)*101);
		}
		int safe=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visited[i][j]==1) continue;
				if(arr[i][j]<=h){
					visited[i][j]=1;
					continue;
				}
				bfs(i,j,h);
				safe++;
			}
		}
		if(maxsafe<safe) maxsafe = safe;
	}
	if(maxsafe==0) cout << "1";
	else cout << maxsafe;
	return 0;
}