#include <iostream>
#include <queue>
using namespace std;
int n,m;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int arr[1001][1001];
int visited[1001][1001]={0,};
bool check(int y, int x){
	if(y<0||x<0||y>=n||x>=m) return false;
	if(visited[y][x]==1) return false;
	if(arr[y][x]==0) return false;
	return true;
}
int main(){
	queue<int> qy,qx,qcnt;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==2){
				qy.push(i); qx.push(j); qcnt.push(0);
				arr[i][j] = 0;
				visited[i][j] = 1;
			}
		}
	}
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		
		arr[cy][cx] = ccnt;
		
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx)){
				visited[ny][nx] = 1;
				qy.push(ny); qx.push(nx); qcnt.push(ccnt+1);
			}
		}
	}	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(visited[i][j]==0&&arr[i][j]!=0) arr[i][j] = -1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ",arr[i][j]);	
		}
		printf("\n");
	}
	return 0;
}