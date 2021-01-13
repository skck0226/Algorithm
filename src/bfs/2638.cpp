#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m;
int arr[101][101];
int zero[101][101];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int check(int vy, int vx){
	if(vy<0||vx<0||vy>=n||vx>=m) return 0;
	if(zero[vy][vx]==-1) return 1;
	return 0;
}
bool check2(int vy, int vx,int visited[][101]){
	if(vy<0||vx<0||vy>=n||vx>=m) return false;
	if(visited[vy][vx]==1) return false;
	if(arr[vy][vx]==1) return false;
	return true;
}
void bfs(int vy, int vx){
	int visited[101][101];
	for(int i=0;i<101;i++){
		memset(visited[i],0,sizeof(int)*101);
	}
	queue<int> qy, qx;
	qy.push(vy); qx.push(vx);
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check2(ny,nx,visited)){
				visited[ny][nx] = 1;
				arr[ny][nx] = -1;
				qy.push(ny); qx.push(nx);
			}
		}
	}
}
int main() {
	queue<int> qy,qx,qcnt;
	int cntFlag = -1;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1){
				qy.push(i); qx.push(j); qcnt.push(0);
				cntFlag = 0;
			}
		}
	}
	bfs(0,0);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			zero[i][j] = arr[i][j];
		}
	}
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		int ccnt = qcnt.front(); qcnt.pop();
		if(cntFlag != ccnt){
			cntFlag = ccnt;	
			bfs(0,0);
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					zero[i][j] = arr[i][j];
				}
			}
		}
		//cout << cy << cx << endl;
		int cnt = 0;
		for(int i=0;i<4;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			cnt += check(ny,nx);
		}
		if(cnt>=2){
			arr[cy][cx] = -1;
		}
		else{
			qy.push(cy); qx.push(cx); qcnt.push(ccnt+1);
		}
	}
	cout << cntFlag+1 ;
	return 0;
}