#include <iostream>
#include <queue>
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[501][501];
int visited[501][501];
bool check(int y, int x){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(visited[y][x]==1) return false;	
	if(arr[y][x]==0) return false;
	return true;
}
int bfs(int y, int x){
	queue<int> qy,qx,qcnt;
	qy.push(y); qx.push(x); qcnt.push(0);
	arr[y][x] = 0;
	visited[y][x] = 1;
	int flag = 0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		flag++;
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx)){
				arr[ny][nx] = 0;
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	return flag;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int maxi = 0;
	int cnt = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==1){
				visited[i][j] = 1;
				cnt++;
				int res = bfs(i,j);
				if(maxi<res) maxi=res;
			}
		}
	}
	cout << cnt << endl << maxi;
	return 0;
}