#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int dy[8] = {1,-1,0,0,-1,-1,1,1};
int dx[8] = {0,0,1,-1,1,-1,-1,1};
int map[51][51];
bool check(int vy, int vx, int visited[][51], int w, int h){
	if(vy<0||vx<0||vy>=h||vx>=w) return false;
	if(visited[vy][vx]==1) return false;
	if(map[vy][vx]==0) return false;
	return true;
}
void bfs(int vy, int vx, int w, int h){
	int visited[51][51];
	for(int i=0;i<51;i++){
			memset(visited[i],0,sizeof(int)*51);
		}
	queue<int> qy,qx;
	qy.push(vy); qx.push(vx);
	visited[vy][vx] = 1; map[vy][vx] = 0;
	while(!qy.empty()){
		int cy = qy.front(); qy.pop();
		int cx = qx.front(); qx.pop();
		for(int i=0;i<8;i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if(check(ny,nx,visited,w,h)){
				visited[ny][nx] = 1;
				map[ny][nx] = 0;
				qy.push(ny); qx.push(nx);
			}
		}
	}
}
int main(){
	while(1){
		for(int i=0;i<51;i++){
			memset(map[i],0,sizeof(int)*51);
		}
		int w,h;
		queue<int> qy,qx;
		scanf("%d %d",&w,&h);
		if(w==0&&h==0) break;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				scanf("%d",&map[i][j]);
				if(map[i][j]==1){
					qy.push(i); qx.push(j);	
				}
			}
		}
		int cnt = 0;
		while(!qy.empty()){
			int cy = qy.front(); qy.pop();
			int cx = qx.front(); qx.pop();
			if(map[cy][cx]==0) continue;
			cnt++;
			bfs(cy,cx,w,h);
		}
		cout << cnt << endl;
	}
	
	return 0;
}