#include <iostream>
#include <queue>
using namespace std;
int n,m;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
int arr[51][51];
int visited[51][51];
bool check(int y, int x, int cnt){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(arr[y][x]==1) return false;
	if(visited[y][x]!=0) return false;
	return true;
}
int main(){
	queue<int> qy,qx,qcnt;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1){
				qy.push(i); qx.push(j); qcnt.push(0);
			}
		}
	}
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		for(int i=0;i<8;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx,ccnt)){
				visited[ny][nx] = ccnt+1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(max<visited[i][j]) max = visited[i][j];	
		}	
	}
	cout << max;
	return 0;
}