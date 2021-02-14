#include <iostream>
#include <queue>

using namespace std;
int n,m;
int arr[251][251];
int visited[251][251];
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
bool check(int y, int x){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(visited[y][x]==1) return false;
	if(arr[y][x]==0) return false;
	return true;
}
void bfs(int y, int x){
	queue<int> qy,qx;
	qy.push(y); qx.push(x);
	visited[y][x] = 1;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		for(int i=0;i<8;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx)){
				visited[ny][nx]=1;
				arr[ny][nx] = 0;
				qy.push(ny); qx.push(nx);
			}
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0) continue;
			bfs(i,j);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}